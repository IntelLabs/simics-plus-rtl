package accel

import chisel3._
import chisel3.util._

class Command extends Bundle {
  val rs1 = UInt(64.W)
  val rs2 = UInt(64.W)
}

class Response extends Bundle {
  val data = UInt(64.W)
}

class MemReq extends Bundle {
  val is_read = Bool()
  val size_in_bytes = UInt(4.W) // 1,2,4,8
  val addr = UInt(64.W)
  val data = UInt(64.W)
}

class MemResp extends Bundle {
  val data = UInt(64.W)
}

class MemIO extends Bundle {
  val req = Decoupled(new MemReq)
  val resp = Flipped(Valid(new MemResp))
}

class CoreIO extends Bundle {
  val cmd = Flipped(Valid(new Command))
  val resp = Valid(new Response)
  val mem = new MemIO
  val busy = Output(Bool())
}
