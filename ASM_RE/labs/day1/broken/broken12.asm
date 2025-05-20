; broken12.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're just moving a string to a register for printing. Not sure why
; it doesn't work?
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     eax; str
    push    str
    call    printf
    add     esp, 8

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:    db "Congrats! You're done with the broken exercises for Day 1!", 0xA, 0
