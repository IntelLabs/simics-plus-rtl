import sys, os, mmap, struct, zlib

def read8(b):
    return struct.unpack("<Q", b)[0]
def write8(n):
    return struct.pack("<Q", n) 

fd = os.open("/sys/bus/pci/devices/0000:00:0c.0/resource0", os.O_RDWR | os.O_SYNC)
m = mmap.mmap(fd, 0, prot=mmap.PROT_READ | mmap.PROT_WRITE)
os.close(fd)

base_address = int(sys.argv[1], 16)
data_in = int(sys.argv[2], 16)

m[0x8:0x10] = write8(base_address + 0x18)
m[0x10:0x18] = write8(base_address + 0x20)
m[0x18:0x20] = write8(data_in)
m[0x0:0x8] = write8(0x8)

data_out = read8(m[0x20:0x28])
expected = zlib.crc32(data_in.to_bytes(8, 'little'))

print("CTRL:    ", hex(read8(m[0x0:0x8])))
print("Source:  ", hex(read8(m[0x8:0x10])))
print("Dest:    ", hex(read8(m[0x10:0x18])))
print("In:      ", hex(read8(m[0x18:0x20])))
print("Out:     ", hex(data_out))
print("Expected:", hex(expected))

if data_out == expected:
    print("PASS")
else:
    print("FAIL")
