; fitb5.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; To cap our adventure into loops off, this lab is going to have you make
; a simple application in assembly. Here, we want you to create a basic
; memory viewer that will print out the memory contents byte-by-byte, in hex.
;
; The start address for the memory region can be found in ESI, and the length
; we want you to print in the LEN variable. Good luck!

main:
    mov     esi, esp

exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
LEN:    dd 1024
