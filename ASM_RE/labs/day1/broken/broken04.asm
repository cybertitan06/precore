; broken4.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; It'll print out a nice "Hello World!" to the screen when its working,
; so see if you can get it to do that!
[BITS 32]

section .text
global  main
extern  printf

main:
    
    mov     eax, 0x0000000000002022
    push    eax
    push    str1
    call    printf
    add     esp, 8

    xor     eax, eax
    mov     al, 2022
    push    eax
    push    str2
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:   db "%x is a nice number", 0xA, 0
str2:   db "Want to know what's nicer though? %d", 0xA, 0
