; debug2.asm - Created by Jered Tupik for Pre-Core 2022
;
; By now you probably know the drill, so let's get on with fixing up
; some buggy code to get some results!
[BITS 32]

section .text
global  main
extern  printf

; Functions are going to form the foundations for almost any program
; you're working on, so it's important to know how they're setup
; and the basics behind them. Here, we've got a quaint little function
; that swaps two numbers (passed in as addresses) for us on the stack. 
; Why isn't it working?
;
; Your objective is to get swap_nums to follow standard cdecl calling
; convention (and appropriate register usage) to get the function working

swap_nums:
    push    ebp
    mov     ebp, esp
    sub     esp, 4

    mov     eax, [ebp+16]
    mov     ecx, [ebp+20]
    mov     edx, [eax]
    mov     [ebp-4], edx
    mov     edx, [ecx]
    mov     [eax], edx
    mov     edx, [ebp-4]
    mov     [ecx], edx

    pop     ebp
    ret

main:

    mov     eax, [num1]
    push    eax
    mov     eax, [num2]
    push    eax
    push    str
    call    printf
    add     esp, 12

    push    num2
    push    num1
    call    swap_nums
    add     esp, 8
    
    mov     eax, [num1]
    push    eax
    mov     eax, [num2]
    push    eax
    push    str
    call    printf
    add     esp, 12

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
num1:   dd  0xABCDEF01
num2:   dd  0x23456789
str:    db "num1: 0x%08x, num2: 0x%08x", 0xA, 0
