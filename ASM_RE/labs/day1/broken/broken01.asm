; broken1.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; It should print a nice welcome message if you can get it working.
.intel_syntax noprefix
.code32

.text
global  main

main:
    
    ; Print Hello World using x86 syscalls
    mov     %edx, len
    mov     %ecx, str
    mov     %ebx, 0x1
    mov     %eax, 0x4
    int     0x80

    ; Return cleanly
    xor     %ebx, %ebx
    mov     %eax, 0x1
    int     0x80

.data

str:    .ascii "Welcome to Pre-Core 2022!", 0xA, 0
len:    equ ($-str)
