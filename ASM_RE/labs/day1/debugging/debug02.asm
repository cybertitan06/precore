; debug2.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; For refernce, all we want to initialize a variable to a nice small
; number
[BITS 32]

section .text
global  main
extern  printf

main:
    xor     ebx, ebx
    push    ebx
    push    str
    call    printf
    add     esp, 8

    mov     bh, 0x42
    push    ebx
    push    str
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:        db "Value: 0x%08x", 0xA, 0
