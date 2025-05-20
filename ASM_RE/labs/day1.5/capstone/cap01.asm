; cap01.asm - Created by Jered Tupik for Pre-Core 2022
;
; Welcome to the Capstone exercises! These exercises are meant to be done if
; you've finished everything else and are looking for something a little bit
; outside of the current day's lecture topics. Overall, they're similar to the 
; Fill-in-the-Blank exercises though.
BITS 32

section .text
global  main
extern  printf


main:

    ; To cap off Day 1's labs, we want you to revisit fitb6.asm and reimplement
    ; swapping without using any intermediate variables, registers, or memory
    ; As a hint, we guarantee this supposed swapping function will always be
    ; swapping two unique variables. This will involve an instruction you're
    ; not yet familiar with, but will be covered over more on Day 2

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
