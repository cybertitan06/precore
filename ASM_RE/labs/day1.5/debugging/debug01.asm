; debug1.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got a small program here that should work correctly but
; just doesn't for some reason. Maybe you can see what we're doing wrong here?
[BITS 32]

section .text
global  main
extern  printf

; This program was meant to be a small showcase on how movzx and movsx work

main:

    push    intr
    call    printf
    add     esp, 4

    mov     esi, arr
    mov     edi, len
loop:
    cmp     edi, 0
    je      exit

    xor     eax, eax
    mov     al, [esi]
    movsx   ebx, al
    movsx   ecx, al

    push    ecx
    push    ebx
    push    str
    call    printf
    add     esp, 12

    inc     esi
    dec     edi
    jmp     loop

exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
arr:    db 255, 0, -43, 20, 45, 127, 129, 30, -4
len:    equ $ - arr

intr:   db "Welcome to the movzx/sx demo. We'll be going through an array to show you how zero and sign extension applies to a range of numbers!", 0xA, 0
str:    db "Zero-Extended: %d, Sign-Extended: %d", 0xA, 0
