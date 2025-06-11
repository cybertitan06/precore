; debug7.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; We're just attempting some multiplication/division over here
[BITS 32]

section .text
global  main
extern  printf

main:
    xor     edx, edx
    mov     eax, 5
    mov     ebx, -5
    mul     ebx
    push    eax
    push    mul_res
    call    printf
    add     esp, 8

    xor     edx, edx
    mov     eax, 5
    mov     ebx, -5
    idiv    ebx         ;Changed div to idiv to account for the negative quotient
    push    eax
    push    div_res
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
mul_res: db "5 * -5 = %d", 0xA, 0
div_res: db "5 / -5 = %d", 0xA, 0
