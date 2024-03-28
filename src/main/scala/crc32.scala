package accel

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._

class Crc32 extends Module {
  val io = IO(new CoreIO())

  // the following table is adapted from:
  // https://github.com/freebsd/freebsd-src/blob/main/sys/libkern/gsb_crc32.c

  val table = RegInit(VecInit(
    "h00000000".U, "h77073096".U, "hee0e612c".U, "h990951ba".U,
    "h076dc419".U, "h706af48f".U, "he963a535".U, "h9e6495a3".U,
    "h0edb8832".U, "h79dcb8a4".U, "he0d5e91e".U, "h97d2d988".U,
	  "h09b64c2b".U, "h7eb17cbd".U, "he7b82d07".U, "h90bf1d91".U,
    "h1db71064".U, "h6ab020f2".U, "hf3b97148".U, "h84be41de".U,	
    "h1adad47d".U, "h6ddde4eb".U, "hf4d4b551".U, "h83d385c7".U,
    "h136c9856".U, "h646ba8c0".U, "hfd62f97a".U, "h8a65c9ec".U,	
    "h14015c4f".U, "h63066cd9".U, "hfa0f3d63".U, "h8d080df5".U,
    "h3b6e20c8".U, "h4c69105e".U, "hd56041e4".U, "ha2677172".U,
    "h3c03e4d1".U, "h4b04d447".U, "hd20d85fd".U, "ha50ab56b".U,
    "h35b5a8fa".U, "h42b2986c".U, "hdbbbc9d6".U, "hacbcf940".U,	
    "h32d86ce3".U, "h45df5c75".U, "hdcd60dcf".U, "habd13d59".U, 
    "h26d930ac".U, "h51de003a".U, "hc8d75180".U, "hbfd06116".U,
    "h21b4f4b5".U, "h56b3c423".U, "hcfba9599".U, "hb8bda50f".U,
    "h2802b89e".U, "h5f058808".U, "hc60cd9b2".U, "hb10be924".U,
    "h2f6f7c87".U, "h58684c11".U, "hc1611dab".U, "hb6662d3d".U,
    "h76dc4190".U, "h01db7106".U, "h98d220bc".U, "hefd5102a".U,
    "h71b18589".U, "h06b6b51f".U, "h9fbfe4a5".U, "he8b8d433".U, 
    "h7807c9a2".U, "h0f00f934".U, "h9609a88e".U, "he10e9818".U,
    "h7f6a0dbb".U, "h086d3d2d".U, "h91646c97".U, "he6635c01".U,
    "h6b6b51f4".U, "h1c6c6162".U, "h856530d8".U, "hf262004e".U,
    "h6c0695ed".U, "h1b01a57b".U, "h8208f4c1".U, "hf50fc457".U,
    "h65b0d9c6".U, "h12b7e950".U, "h8bbeb8ea".U, "hfcb9887c".U,
    "h62dd1ddf".U, "h15da2d49".U, "h8cd37cf3".U, "hfbd44c65".U,
    "h4db26158".U, "h3ab551ce".U, "ha3bc0074".U, "hd4bb30e2".U,
    "h4adfa541".U, "h3dd895d7".U, "ha4d1c46d".U, "hd3d6f4fb".U,
    "h4369e96a".U, "h346ed9fc".U, "had678846".U, "hda60b8d0".U,
    "h44042d73".U, "h33031de5".U, "haa0a4c5f".U, "hdd0d7cc9".U,
    "h5005713c".U, "h270241aa".U, "hbe0b1010".U, "hc90c2086".U,
    "h5768b525".U, "h206f85b3".U, "hb966d409".U, "hce61e49f".U,
    "h5edef90e".U, "h29d9c998".U, "hb0d09822".U, "hc7d7a8b4".U,
    "h59b33d17".U, "h2eb40d81".U, "hb7bd5c3b".U, "hc0ba6cad".U,
    "hedb88320".U, "h9abfb3b6".U, "h03b6e20c".U, "h74b1d29a".U,
    "head54739".U, "h9dd277af".U, "h04db2615".U, "h73dc1683".U,
    "he3630b12".U, "h94643b84".U, "h0d6d6a3e".U, "h7a6a5aa8".U,
    "he40ecf0b".U, "h9309ff9d".U, "h0a00ae27".U, "h7d079eb1".U,
    "hf00f9344".U, "h8708a3d2".U, "h1e01f268".U, "h6906c2fe".U,
    "hf762575d".U, "h806567cb".U, "h196c3671".U, "h6e6b06e7".U,
    "hfed41b76".U, "h89d32be0".U, "h10da7a5a".U, "h67dd4acc".U,
    "hf9b9df6f".U, "h8ebeeff9".U, "h17b7be43".U, "h60b08ed5".U,
    "hd6d6a3e8".U, "ha1d1937e".U, "h38d8c2c4".U, "h4fdff252".U,
    "hd1bb67f1".U, "ha6bc5767".U, "h3fb506dd".U, "h48b2364b".U,
    "hd80d2bda".U, "haf0a1b4c".U, "h36034af6".U, "h41047a60".U,
    "hdf60efc3".U, "ha867df55".U, "h316e8eef".U, "h4669be79".U,
    "hcb61b38c".U, "hbc66831a".U, "h256fd2a0".U, "h5268e236".U,
    "hcc0c7795".U, "hbb0b4703".U, "h220216b9".U, "h5505262f".U,
    "hc5ba3bbe".U, "hb2bd0b28".U, "h2bb45a92".U, "h5cb36a04".U,
    "hc2d7ffa7".U, "hb5d0cf31".U, "h2cd99e8b".U, "h5bdeae1d".U,
    "h9b64c2b0".U, "hec63f226".U, "h756aa39c".U, "h026d930a".U,
    "h9c0906a9".U, "heb0e363f".U, "h72076785".U, "h05005713".U,
    "h95bf4a82".U, "he2b87a14".U, "h7bb12bae".U, "h0cb61b38".U,
    "h92d28e9b".U, "he5d5be0d".U, "h7cdcefb7".U, "h0bdbdf21".U,
    "h86d3d2d4".U, "hf1d4e242".U, "h68ddb3f8".U, "h1fda836e".U,
    "h81be16cd".U, "hf6b9265b".U, "h6fb077e1".U, "h18b74777".U,
    "h88085ae6".U, "hff0f6a70".U, "h66063bca".U, "h11010b5c".U,
    "h8f659eff".U, "hf862ae69".U, "h616bffd3".U, "h166ccf45".U,
    "ha00ae278".U, "hd70dd2ee".U, "h4e048354".U, "h3903b3c2".U,
    "ha7672661".U, "hd06016f7".U, "h4969474d".U, "h3e6e77db".U,
    "haed16a4a".U, "hd9d65adc".U, "h40df0b66".U, "h37d83bf0".U,
    "ha9bcae53".U, "hdebb9ec5".U, "h47b2cf7f".U, "h30b5ffe9".U,
    "hbdbdf21c".U, "hcabac28a".U, "h53b39330".U, "h24b4a3a6".U,
    "hbad03605".U, "hcdd70693".U, "h54de5729".U, "h23d967bf".U,
    "hb3667a2e".U, "hc4614ab8".U, "h5d681b02".U, "h2a6f2b94".U,
    "hb40bbe37".U, "hc30c8ea1".U, "h5a05df1b".U, "h2d02ef8d".U))

  // state elements
  val s_idle :: s_read :: s_write :: s_resp :: Nil = Enum(4)
  val state = RegInit(s_idle)
  val src_addr = RegInit(0.U(64.W))
  val dst_addr = RegInit(0.U(64.W))
  val len = RegInit(0.U(64.W))
  val crc32_val = RegInit("hFFFFFFFF".U)
  // assign default output values
  io.busy := (state =/= s_idle)
  io.mem.req.valid := false.B // override below if needed
  io.mem.req.bits := DontCare
  io.resp.valid := false.B // override below if needed
  io.resp.bits := DontCare

  when(state === s_idle && io.cmd.valid) {
    when (io.cmd.bits.rs1 =/= 0.U) { // setup
      src_addr := io.cmd.bits.rs1
      dst_addr := io.cmd.bits.rs2
      printf("CRC32 RTL: CMD with src: 0x%x, dst: 0x%x\n", io.cmd.bits.rs1.asUInt, io.cmd.bits.rs2.asUInt)
      state := s_resp
    }.otherwise { // processing
      len := io.cmd.bits.rs2
      state := Mux(io.cmd.bits.rs2 === 0.U, s_resp, s_read) // handle trivial zero length case by skipping memory reads
      printf("CRC32 RTL: CMD with len: 0x%x Recall src: 0x%x, dst: 0x%x\n", io.cmd.bits.rs2.asUInt, src_addr.asUInt, dst_addr.asUInt)
    }
  }.elsewhen(state === s_read) {
    io.mem.req.valid := true.B
    io.mem.req.bits.is_read := true.B
    io.mem.req.bits.addr := src_addr
    io.mem.req.bits.size_in_bytes := 1.U
    io.mem.req.bits.data := DontCare
    //printf("CRC32 RTL: Mem read at address 0x%x\n", io.mem.req.bits.addr.asUInt)
    // keep incrementing as it fires
  }.elsewhen(state === s_write) {
    io.mem.req.valid := true.B
    io.mem.req.bits.is_read := false.B
    io.mem.req.bits.addr := dst_addr
    io.mem.req.bits.size_in_bytes := 4.U
    io.mem.req.bits.data := (crc32_val ^ "hFFFFFFFF".U)
    //printf("CRC32 RTL: Mem write at address 0x%x with data 0x%x\n", io.mem.req.bits.addr.asUInt, io.mem.req.bits.data.asUInt)
  }.elsewhen(state === s_resp) {
    io.resp.valid := true.B
    io.resp.bits.data := (crc32_val ^ "hFFFFFFFF".U)
    state := s_idle // reset all states
    len := 0.U
    crc32_val := "hFFFFFFFF".U
    //printf("CRC32 RTL: Response with data 0x%x\n", io.resp.bits.data.asUInt)
  }

  // a memory read/write has been accepted
  when (io.mem.req.fire) { 
    when (state === s_read) { // read accepted: do more reads or end
      src_addr := src_addr + 1.U
      when (len === 1.U) {
        state := s_write
      }
      len := len - 1.U
    }.otherwise { // write accepted
      state := s_resp // now end
    }
  }

  // the memory (read) response has arrived: do computation here
  when (io.mem.resp.valid) {
    //printf("CRC32 RTL: Mem response with data 0x%x\n", io.mem.resp.bits.data.asUInt)
    val nLookupIndex = ((crc32_val ^ (io.mem.resp.bits.data & "hFF".U)) & "hFF".U).asTypeOf(UInt(8.W))
    crc32_val := (crc32_val >> 8) ^ table(nLookupIndex)
  }
}

object DefaultCirctArgs {
  // Using "--preserve-aggregate=all" below generates signals which
  // use SystemVerilog packed structs. Unfortunately not fully yet supported by verilator:
  // https://github.com/verilator/verilator/issues/860
  val args = Array("--preserve-aggregate=1d-vec", "--scalarize-public-modules=false", "--scalarize-ext-modules=true", "--lowering-options=disallowLocalVariables,disallowPackedArrays,explicitBitcast,disallowPortDeclSharing", "--emit-chisel-asserts-as-sva")
}

object DefaultFirrtlArgs {
  // Emit System Verilog, one module per file by default
  val args = Array("--split-verilog")
}

object Crc32 extends App {
    ChiselStage.emitSystemVerilogFile(new Crc32, args ++ DefaultFirrtlArgs.args, DefaultCirctArgs.args)
}
