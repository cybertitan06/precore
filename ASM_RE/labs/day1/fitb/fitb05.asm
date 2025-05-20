; fitb5.asm - Created by Jered Tupik for Pre-Core 2022
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

    ; This lab should hopefully be a bit simpler for a fill-in-the-blank
    ; lab, as all we want you to do here is execute and store the 
    ; quotient/remainder for a couple of operations. These are:
    ;   1 - Calculate 20 / 2 and store the remainder in rem1
    ;   2 - Calculate 11 / 5 and store the quotient in quo1
    ;   3 - Calculate 0x1000 / 2 and store the quotient in quo2
    ;   4 - Calculate 0 / 1 and store the remainder in rem2
    
    ;   1 - Calculate 20 / 2 and store the remainder in rem1
    
    ;   2 - Calculate 11 / 5 and store the quotient in quo1
    
    ;   3 - Calculate 0x1000 / 2 and store the quotient in quo2
    
    ;   4 - Calculate 0 / 1 and store the remainder in rem2
    
    ; DONT EDIT BELOW THIS LINE
    push    0
    push    dword [rem1]
    push    str1
    call    printf
    add     esp, 12
    cmp     dword [rem1], 0
    jne     bad

    push    2
    push    dword [quo1]
    push    str2
    call    printf
    add     esp, 12
    cmp     dword [quo1], 2
    jne     bad

    push    2048
    push    dword [quo2]
    push    str3
    call    printf
    add     esp, 12
    cmp     dword [quo2], 2048
    jne     bad

    
    push    0   
    push    dword [rem2]
    push    str4
    call    printf
    add     esp, 12
    cmp     dword [rem2], 0
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
str1:       db "rem1 = %d, expected %d", 0xA, 0
str2:       db "quo1 = %d, expected %d", 0xA, 0
str3:       db "quo2 = %d, expected %d", 0xA, 0
str4:       db "rem2 = %d, expected %d", 0xA, 0

success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
quo1:   resd 1
quo2:   resd 1
rem1:   resd 1
rem2:   resd 1
