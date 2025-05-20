; broken5.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're trying to clear some bytes from a register
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     ebx, 0x12345678
    push    ebx
    push    str1
    call    printf
    add     esp, 8
    
    xor     bxhl, bxhl
    push    ebx
    push    str2
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:   db "EBX before clearing bytes: 0x%08x", 0xA, 0
str2:   db "EBX after clearing bytes: 0x%08x", 0xA, 0
