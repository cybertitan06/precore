; broken10.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're trying to add a number and store it at our variable
[BITS 32]

section .text
global  main
extern  printf

main:
    push    dword [num]
    push    str1
    call    printf
    add     esp, 8

    add     num, 2022
    push    dword [num]
    push    str2
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:    db "Value before adding is %d", 0xA, 0
str2:    db "Value after adding is %d", 0xA, 0

section .bss
num:    resw 1
