; debug3.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; We were trying to just do some simple register moves, but it
; seems to bug out
[BITS 32]

section .text
global  main

main:
    mov     esp, 0
    pop     eax
    mov     eax, esp
    mov     ebx, ecx
    
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
