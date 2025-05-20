; fitb6.asm - Created by Jered Tupik for Pre-Core 2022
;
; Welcome to the Fill-in-the-Blank exercises! For this group of labs, we're
; giving you code that already has most of the functionality already
; implemented, we just want you to fill in the blank spots to get everything
; all tied together. Some of these labs will tie together, so you might find
; yourself copying previous code.
BITS 32

section .text
global  main
extern  printf


main:

    ; To cap the fill-in labs off, we're returning back to something
    ; that you'll probably experience plenty of in high-level
    ; languages, swapping variables.
    ; Here, your task is to swap around several pairs of registers,
    ; and we've provided a (tmp) variable in the bss section if you
    ; need it. Please don't cheat by just moving the values directly,
    ; so pretend you don't know what's in the registesr here. Good luck!
    
    mov     eax, 0x13579BDF
    mov     edi, 0x02468ACE
    ; Swap the registers EAX and EDI
    

    cmp     edi, 0x13579BDF
    jne     bad
    cmp     eax, 0x02468ACE
    jne     bad

    mov     ebx, 1111000000001111b
    mov     ecx, 01234
    ; Swap the ECX and EBX registers

    cmp     ebx, 01234
    jne     bad
    cmp     ecx, 1111000000001111b
    jne     bad
 
    push    success
    jmp     exit
bad:
    push    failure
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
tmp:    resd 1
