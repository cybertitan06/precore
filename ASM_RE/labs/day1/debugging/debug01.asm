; debug1.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; For refernce, all we're doing here is just storing a value
; in EBX and verifying it's stored correctly.
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     ebx, 0x546729AB
    push    byte 0x42
    push    str
    call    printf
    add     esp, 8

    mov     bl, 0x42
    push    ebx
    push    str
    call    printf
    add     esp, 8

    ;xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:        db "Value: 0x%08x", 0xA, 0
