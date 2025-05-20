; extra1.asm - Created by Jered Tupik for Pre-Core 2022
;
; In case y'all are bored or get through all the other Assembly
; labs early, here's a bit of extra content to try your hand at.
; Please note: All of the extra exercises are going to be outside
; of the scope of the material presented in the class, but they
; do have real world applications. In other words, you're going
; to need to use the Internet to do some research if you're not
; familiar with the topic. Good luck!
[BITS 32]

section .text
global  _start

; Try seeing if you can figure out how to execute /bin/sh purely
; using Assembly (don't use the C linker here to call some high-level
; function). As a hint, take a look at syscalls for this, they're pretty 
; useful and provide a lot of functionality. Additionally, make sure you're
; passing in PROPER arguments to the syscall.

_start:

    ; NOTE: If you execute the syscall properly, the below
    ; will never actually be called. Still, it helps to be nice.
exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
