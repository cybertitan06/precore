; fitb1.asm - Created by Jered Tupik for Pre-Core 2022
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
    
    mov     esi, arr
    ; For this lab, we've got an array (contiguous block of values) in
    ; memory that we want to initialize to several different values. Your
    ; objective is to manually store those values into the array. arr is stored
    ; in esi here for your use, so try not to overwrite that register
    ;
    ; 
    ; Init: arr = [~, ~, ~, ~, ~]
    ; Goal: arr = [255, 01337, 2022, 0x2021, 10101010b]

    ; DONT EDIT BELOW HERE. This part of the code verifies your result and
    ; provides debugging information
    mov     edi, goal_arr
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    0
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
    add     esi, 4    
    add     edi, 4    
    
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    1
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
    add     esi, 4    
    add     edi, 4    
    
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    2
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
    add     esi, 4    
    add     edi, 4    
    
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    3
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
    add     esi, 4    
    add     edi, 4    
    
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    4
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
 
    push    success
    call    printf
    add     esp, 4    
    jmp     exit

bad:
    push    failure
    call    printf
    add     esp, 4
exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
at_expected:db "Value at offset %d is %d, expected %d", 0xA, 0
goal_arr:   dd 255, 01337, 2022, 0x2021, 10101010b
success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
arr:        resd 5
