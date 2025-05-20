; fitb3.asm - Created by Jered Tupik for Pre-Core 2022
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
    ; This lab is a continuation of the concepts introduced fitb2.asm, where 
    ; we'd like you to apply your new-found for loop knowledge to create
    ; an array of increasing values in memory, from 0 to 255. We've implemented
    ; a loop-based checking function below to verify it all, and have filled
    ; the structure of the loop, so its just up to you to implement the
    ; internals
    ;
    ; INIT: arr = [~] x 256
    ; GOAL: arr = [0, 1, 2, 3, 4, ..., 255]

    ; 1) Initialize a loop counter. Feel free to use anything you'd like here
init_loop:
    ; 2) Check if the loop counter has gone past the last index. If so, get
    ; out of the loop and over to check_init
    ;je check_init ; Uncomment once you've got the check done

    ; 3) Store the value that we desire into the index in the array

    ; 4) Increment your loop counter and array address

    jmp     init_loop
    
check_init:
    mov     esi, arr
check_loop:
    cmp     edi, 256
    je      good
    
    push    edi
    push    dword [esi]
    push    edi
    push    at_expected
    call    printf
    add     esp, 16 
   
    cmp     [esi], edi
    jne     bad
    inc     edi
    add     esi, 4
    jmp     check_loop
 
good:
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
at_expected:db "Value at offset %d is %d, expected %d", 0xA, 0
success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
arr:        resd 256
