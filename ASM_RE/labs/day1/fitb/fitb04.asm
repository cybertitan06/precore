; fitb4.asm - Created by Jered Tupik for Pre-Core 2022
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

    ; This lab is two combined labs concentrated around an overall topic that
    ; was combined to reduce the amount of repeated code between labs.
    ; For this lab, there are four blocks of code we want you to implement:
    ;   1 - Implement x - 1024 using only addition operations
    ;   2 - Implement x + 1337 using only subtraction operations
    ;   3 - Implement 16 * x using only addition operations
    ;   4 - Implement -5 * x using only subtraction operations
    ;
    ; Bonus points (figuratively, not literally) if you can do 1 + 2
    ; using Two's Complement Arithmetic rather than the simpler method.
    ; Two's complement is what's used internally though.
    
    ; Initializing the registers
    mov     eax, 3212021
    mov     ebx, 0xABCDEF
    mov     ecx, 1024
    mov     edx, 99

    ;   1 - Implement num1 = EAX - 1024 using only addition operations
    
    ;   2 - Implement num2 = EBX + 1337 using only subtraction operations
    
    ;   3 - Implement num3 = 16 * ECX using only addition operations
    
    ;   4 - Implement num4 = -5 * EDX using only subtraction operations

    ; DONT EDIT BELOW THIS LINE
    push    0x30FEF4
    push    dword [num1]
    push    str1
    call    printf
    add     esp, 12
    cmp     dword [num1], 0x30FEF4
    jne     bad

    push    0xABD328
    push    dword [num2]
    push    str2
    call    printf
    add     esp, 12
    cmp     dword [num2], 0xABD328
    jne     bad

    push    0x4000
    push    dword [num3]
    push    str3
    call    printf
    add     esp, 12
    cmp     dword [num3], 0x4000
    jne     bad

    
    push    0xFFFFFE11    
    push    dword [num4]
    push    str4
    call    printf
    add     esp, 12
    cmp     dword [num4], 0xFFFFFE11
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
str1:       db "num1 = %d, expected %d", 0xA, 0
str2:       db "num2 = %d, expected %d", 0xA, 0
str3:       db "num3 = %d, expected %d", 0xA, 0
str4:       db "num4 = %d, expected %d", 0xA, 0

success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
num1:   resd 1
num2:   resd 1
num3:   resd 1
num4:   resd 1
