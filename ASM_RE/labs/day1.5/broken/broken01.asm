; broken1.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got some code that, for whatever reason, isn't able to compile
; correctly. We can't understand the errors, but perhaps all you big-brained
; people can figure it out and get it working?
[BITS 32]

section .text
global  main
extern  printf


; For this lab, we were trying mess around with movzx and movsx to show
; the differences between the two, but we can't get the example program to
; compile. 

main:

    xor     ebx, ebx
    mov     bl, 10001111b
    movzx   eax, bl
    movsx   ecx, bl
    push    ecx
    push    eax
    push    ebx
    push    str
    call    printf
    add     esp, 16

    xor     ebx, ebx
    mov     bx, 0x8000
    movzx   ah, bh
    movsx   cl, bx
    push    ecx
    push    eax
    push    ebx
    push    str
    call    printf
    add     esp, 16

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:   db "Orig: %d, Zero-Extended: %d, Sign-Extended: %d", 0xA, 0
