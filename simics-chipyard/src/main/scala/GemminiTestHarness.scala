package simics

import chisel3._
import chisel3.experimental.SourceInfo
import chisel3.util._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.prci.ClockSinkParameters
import freechips.rocketchip.rocket._
import freechips.rocketchip.tile._
import freechips.rocketchip.tilelink._
import gemmini.Arithmetic._
import org.chipsalliance.cde.config._
import gemmini._

case object SimicsGemminiArrayConfigKey extends Field[Option[GemminiArrayConfig[Data, Float, Float]]](None)
case object DumpWaveform extends Field[Boolean](false)
case object SimicsFakeCoreParams extends CoreParams {
  val useVM: Boolean = false
  val useHypervisor: Boolean = false
  val useUser: Boolean = false
  val useSupervisor: Boolean = false
  val useDebug: Boolean = false
  val useAtomics: Boolean = false
  val useAtomicsOnlyForIO: Boolean = false
  val useCompressed: Boolean = false
  override val useVector: Boolean = false
  val useSCIE: Boolean = false
  val useRVE: Boolean = false
  val mulDiv: Option[MulDivParams] = None
  val fpu: Option[FPUParams] = None
  val fetchWidth: Int = 1
  val decodeWidth: Int = 1
  val retireWidth: Int = 2
  val instBits: Int = if (useCompressed) 16 else 32
  val nLocalInterrupts: Int = 15
  val nPMPs: Int = 0
  val nBreakpoints: Int = 0
  val useBPWatch: Boolean = false
  val nPerfCounters: Int = 29
  val haveBasicCounters: Boolean = true
  val haveFSDirty: Boolean = false
  val misaWritable: Boolean = false
  val haveCFlush: Boolean = false
  val nL2TLBEntries: Int = 0
  val mtvecInit: Option[BigInt] = Some(BigInt(0))
  val mtvecWritable: Boolean = true
  val nL2TLBWays: Int = 1
  val lrscCycles: Int = 80
  val mcontextWidth: Int = 0
  val scontextWidth: Int = 0
  val useNMI: Boolean = true
  val nPTECacheEntries: Int = 0
  val traceHasWdata: Boolean = false
  val useConditionalZero: Boolean = false
  val bootFreqHz: BigInt = 1000000000L
  val pmpGranularity: Int = 0
  val xLen: Int = 64
}
case object SimicsFakeTileParams extends TileParams {
  val core: CoreParams = SimicsFakeCoreParams
  val icache: Option[ICacheParams] = None
  val dcache: Option[DCacheParams] = Some(DCacheParams(
    nSets = 1,
    nWays = 1,
    nMSHRs = 0,
    scratch = Some(1)
  ))
  val btb: Option[BTBParams] = None
  val tileId: Int = 0
  val blockerCtrlAddr: Option[BigInt] = None
  val baseName: String = "pcie_gemmini_tile"
  val uniqueName: String = s"${baseName}_$tileId"
  val clockSinkParams: ClockSinkParameters = ClockSinkParameters()
}

class SimicsGemminiConfig extends Config((site, here, up) => {
  case SimicsGemminiArrayConfigKey => Some(GemminiFPConfigs.FP32DefaultConfig.copy(
    sp_singleported = false,
    tile_latency = 0
  ))
  case XLen => 64
  case PgLevels => 3
  case DumpWaveform => false
})

class PcieMemReq(busWidth: Int, xacnWidth: Int) extends Bundle {
  val addr = UInt(64.W)
  val op = UInt(1.W)
  val data = UInt((busWidth * 8).W)
  val mask = UInt(busWidth.W)
  val len = UInt((log2Up(log2Up(xacnWidth) + 1) + 1).W)
  val id = UInt(8.W)
}

class PcieMemResp(busWidth: Int, xacnWidth: Int) extends Bundle {
  val data = UInt((busWidth * 8).W)
  val denied = Bool()
  val len = UInt((log2Up(xacnWidth) + 1).W)
  val op = UInt(1.W)
  val id = UInt(8.W)
}

class PcieMemTLWrapper(busWidth: Int, xacnWidth: Int)
                      (implicit p: Parameters) extends LazyModule {
  val node = TLManagerNode(Seq(
    TLSlavePortParameters.v1(
      managers = Seq(
        TLSlaveParameters.v2(
          address = Seq(AddressSet(0x0, x"ffff_ffffffff")),
          supports = TLMasterToSlaveTransferSizes(
            get = TransferSizes(1, xacnWidth),
            putFull = TransferSizes(1, xacnWidth),
            putPartial = TransferSizes(1, xacnWidth)
          )
        )
      ),
      beatBytes = busWidth
    )
  ))

  class PcieMemTLWrapperImp(outer: PcieMemTLWrapper) extends LazyModuleImp(outer) {
    val io = IO(new Bundle {
      val req = Decoupled(new PcieMemReq(busWidth, xacnWidth))
      val resp = Flipped(Decoupled(new PcieMemResp(busWidth, xacnWidth)))
    })

    val (tlA, tlD) = outer.node.in.head._1 match { case x => (x.a, x.d) }

    io.req.bits.addr := tlA.bits.address
    io.req.bits.data := tlA.bits.data
    io.req.bits.op := Mux(tlA.bits.opcode === TLMessages.Get, 0.U, 1.U)
    io.req.bits.mask := tlA.bits.mask
    io.req.bits.len := tlA.bits.size
    io.req.bits.id := tlA.bits.source
    io.req.valid := tlA.valid
    tlA.ready := io.req.ready

    tlD.bits := DontCare
    tlD.bits.data := io.resp.bits.data
    tlD.bits.denied := io.resp.bits.denied
    tlD.bits.size := io.resp.bits.len
    tlD.bits.opcode := Mux(io.resp.bits.op.asBool, TLMessages.AccessAck, TLMessages.AccessAckData)
    tlD.bits.source := io.resp.bits.id
    tlD.valid := io.resp.valid
    io.resp.ready := tlD.ready
  }

  lazy val module = new PcieMemTLWrapperImp(this)
}

class GemminiWrapper[T <: Data](config: GemminiArrayConfig[T, Float, Float], arithmetic: Arithmetic[T])
                                                   (implicit p: Parameters) extends LazyModule {
  val tileNode = TLEphemeralNode()(ValName("diplomatic_tile_master"))
  val q = p.alterMap(Map(
    TileKey -> SimicsFakeTileParams,
    TileVisibilityNodeKey -> tileNode,
    LookupByHartId -> HartsWontDeduplicate(SimicsFakeTileParams)
  ))
  val lazyGemmini = LazyModule(new Gemmini(config)(arithmetic, q))
  tileNode := lazyGemmini.spad.id_node

  class GemminiWrapperImp(outer: GemminiWrapper[T]) extends LazyModuleImp(outer) {
    val gemmini = lazyGemmini.module
    val io = IO(new Bundle {
      val cmd = Flipped(Decoupled(new RoCCCommand()(q)))
      val busy = Output(Bool())
    })

    val inBundle = tileNode.in.head._1
    val outBundle = tileNode.out.head._1
    outBundle.a <> inBundle.a
    inBundle.d <> outBundle.d

    gemmini.io.cmd <> io.cmd
    io.busy := gemmini.io.busy

    gemmini.io.ptw <> DontCare
    gemmini.io.ptw.map(_.req).foreach(_.ready := false.B)
    gemmini.io.ptw.map(_.resp).foreach(_.valid := false.B)
    gemmini.io.resp.ready := false.B
    gemmini.io.mem <> DontCare
    gemmini.io.mem.req.ready := false.B
    gemmini.io.mem.resp.valid := false.B
    gemmini.io.exception := false.B
    gemmini.io.fpu_req.ready := false.B
    gemmini.io.fpu_resp.bits <> DontCare
    gemmini.io.fpu_resp.valid := false.B
  }
  lazy val module = new GemminiWrapperImp(this)
}

class LazyGemminiTestHarness()(implicit p: Parameters) extends LazyModule {
  val gemminiConfig = p(SimicsGemminiArrayConfigKey).get
  val busWidth = gemminiConfig.dma_buswidth / 8
  val xacnWidth = gemminiConfig.dma_maxbytes

  val lazyGemminiWrapper = LazyModule(new GemminiWrapper(gemminiConfig, FloatArithmetic.asInstanceOf[Arithmetic[Data]]))
  val lazyPcieWrapper = LazyModule(new PcieMemTLWrapper(busWidth, xacnWidth))

  lazyPcieWrapper.node := lazyGemminiWrapper.tileNode

  class LazyGemminiTestHarnessImp(outer: LazyGemminiTestHarness) extends LazyModuleImp(outer) {
    val gemminiWrapper = lazyGemminiWrapper.module
    val pcieWrapper = lazyPcieWrapper.module

   val io = IO(new Bundle {
     val pcieMemReq = Decoupled(new PcieMemReq(busWidth, xacnWidth))
     val pcieMemResp = Flipped(Decoupled(new PcieMemResp(busWidth, xacnWidth)))
     val rocc = Flipped(Decoupled(new Bundle {
       val inst = UInt(32.W)
       val rs1 = UInt(64.W)
       val rs2 = UInt(64.W)
     }))
     val busy = Output(Bool())
   })

    io.pcieMemReq.valid := pcieWrapper.io.req.valid
    io.pcieMemReq.bits := pcieWrapper.io.req.bits
    pcieWrapper.io.req.ready := io.pcieMemReq.ready

    pcieWrapper.io.resp.bits := io.pcieMemResp.bits
    pcieWrapper.io.resp.valid := io.pcieMemResp.valid
    io.pcieMemResp.ready := pcieWrapper.io.resp.ready

    gemminiWrapper.io.cmd.bits.status := 0.U.asTypeOf(gemminiWrapper.io.cmd.bits.status.cloneType)
    gemminiWrapper.io.cmd.bits.rs1 := io.rocc.bits.rs1
    gemminiWrapper.io.cmd.bits.rs2 := io.rocc.bits.rs2
    gemminiWrapper.io.cmd.bits.inst := io.rocc.bits.inst.asTypeOf(gemminiWrapper.io.cmd.bits.inst.cloneType)
    gemminiWrapper.io.cmd.valid := io.rocc.valid
    io.rocc.ready := gemminiWrapper.io.cmd.ready

    val busy = RegInit(false.B)
    val gemminiBusy = gemminiWrapper.io.busy
    when (io.rocc.fire) {
      busy := true.B
    }.elsewhen (RegNext(gemminiBusy) && !gemminiBusy) { // falling edge
      busy := false.B
    }
    io.busy := busy
  }

  lazy val module = new LazyGemminiTestHarnessImp(this)
}

class WaveformDumper extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock = Input(Bool())
  })
  setInline("WaveformDumper.v",
  """
      |module WaveformDumper(input clock);
      |    initial begin
      |        $dumpfile("bb.fst");
      |        $dumpvars();
      |    end
      |endmodule
      |""".stripMargin)
}

class GemminiTestHarness()(implicit p: Parameters) extends Module {
  val lazyHarness = LazyModule(new LazyGemminiTestHarness())
  val harness = Module(lazyHarness.module)
  if (p(DumpWaveform)) {
    val dumper = Module(new WaveformDumper())
    dumper.io.clock := clock.asBool
  }
  val gemminiConfig = p(SimicsGemminiArrayConfigKey).get
  val busWidth = gemminiConfig.dma_buswidth / 8
  val xacnWidth = gemminiConfig.dma_maxbytes

  val io = IO(new Bundle {
    val pcieMemReq = Decoupled(new PcieMemReq(busWidth, xacnWidth))
    val pcieMemResp = Flipped(Decoupled(new PcieMemResp(busWidth, xacnWidth)))
    val rocc = Flipped(Decoupled(lazyHarness.module.io.rocc.bits.cloneType))
    val busy = Output(Bool())
  })
  io.pcieMemReq :<>= harness.io.pcieMemReq
  harness.io.pcieMemResp :<>= io.pcieMemResp
  harness.io.rocc :<>= io.rocc
  io.busy := harness.io.busy

  val printf_cond = Wire(Bool())
  printf_cond := true.B
  dontTouch(printf_cond)  // compatibility with printf checks in chipyard
}
