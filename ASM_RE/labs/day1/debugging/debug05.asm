; debug5.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; We're just throwing some numbers at memory here.
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     dword [num], 0xFFFF
    mov     word [num], 0x00
    
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .bss
num:   resb 4
