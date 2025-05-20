; cap02.asm - Created by Jered Tupik for Pre-Core 2022

[BITS 32]

section .text
global  main
extern  printf

; Here, we're giving you an array and length value. Write a program that will 
; reverse the entire array in memory.

main:

test:
    ; DONT EDIT BELOW THIS LINE
    mov     esi, arr
    mov     edi, rev_arr
    mov     cx, [len]
    xor     eax, eax
check_loop:
    cmp     ecx, 0
    je      all_good
    mov     ax, word [esi]
    cmp     ax, word [edi]
    jne     some_bad    
    add     esi, 2
    add     edi, 2
    dec     ecx
    jmp     check_loop

all_good:
    push    good
    jmp     exit
some_bad:
    push    bad   
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
arr:        dw 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF
rev_arr:    dw 0xF, 0xE, 0xD, 0xC, 0xB, 0xA, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
len:         dw 16

good:       db "Looks reversed to me!", 0xA, 0
bad:        db "Something doesn't look quite right.", 0xA, 0
