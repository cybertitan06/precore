; broken3.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; It's meant to move a couple bytes into several registers, but it
; isn't compiling quite right...
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     rax, [num2]
    push    rax
    mov     rax, [num1]
    push    rax
    push    str
    call    printf
    add     rsp, 12

    xor     rbx, rbx
    mov     rax, 0x1
    int     0x80

section .data

num1:   dd  3
num2:   dd  0x2022
str:    db  "Welcome to Broken Lab %d, Pre-Core 0x%x", 0xA, 0
