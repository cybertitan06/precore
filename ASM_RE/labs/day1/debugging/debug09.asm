; debug9.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; We've got a couple numbers we've initialized in memory, but they're
; not turning out like we expect them to
[BITS 32]

section .text
global  main
extern  printf

main:
    push    42
    mov     eax, [num1]
    push    eax
    push    str
    call    printf
    add     esp, 12

    push    100
    mov     eax, [num2]
    push    eax
    push    str
    call    printf
    add     esp, 12
    
    push    21
    mov     eax, [num3]
    push    eax
    push    str
    call    printf
    add     esp, 12
    
    push    20
    mov     eax, [num4]
    push    eax
    push    str
    call    printf
    add     esp, 12

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:    db "num is %d, should be %d", 0xA, 0
num1:   dd 42
num2:   dd 01100100b
num3:   dd 0x15
num4:   dd 020
