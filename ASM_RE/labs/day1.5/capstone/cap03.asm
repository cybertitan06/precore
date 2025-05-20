; cap03.asm - Created by Jered Tupik for Pre-Core 2022

[BITS 32]

section .text
global  main
extern  printf

; Earlier we had you do some custom push/pop implementaitions to prove
; you knew how to do the stack. Now, how about we try that with call and
; ret instead? Good luck!

; Given the function address in EAX and the return address in EBX, perform 
; a call manually
my_call:

; Performs the function of a ret statement
my_ret:

print_func:
    push    str1
    call    printf
    add     esp, 4
    jmp     my_ret

main:
    mov     ebx, exit
    mov     eax, print_func
    jmp     my_call

exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:   db "Hey, it looks like you managed to call this correctly! Nice.", 0xA, 0
