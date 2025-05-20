; debug3.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got a small program here that should work correctly but
; just doesn't for some reason. Maybe you can see what we're doing wrong here?
[BITS 32]

section .text
global  main
extern  printf

; cmp's are also really important to assembly programs and conditional
; logic in general.

main:

    ; As one of Assembly's boolean logic functions, cmp is important for
    ; performing checks for us. For example, let's do if (num > 0 && num < 10)
    xor     eax, eax
    mov     al, [num]
    cmp     eax, 0
    cmp     eax, 10
    jg      check2
    mov     esi, bad1
    jmp     print1
check2:
    mov     esi, good1
    jl      print1
    mov     esi, bad1
print1:
    push    esi
    call    printf
    add     esp, 4

    ; cmp and jmp also go pretty close together, where you can control where
    ; execution ends up. Watch as we confirm 0 < 0xFF
    mov     esi, bad2
    mov     eax, 0
    mov     ebx, 0xFF
    cmp     eax, ebx
    jmp     print2
    mov     esi, good2
print2:
    push    esi
    call    printf
    add     esp, 4
    
exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
num:    db  5
good1:  db "Yep, 5 is between 0 and 10 here", 0xA, 0
bad1:   db "Wait, when did 5 become less than zero?", 0xA, 0
good2:  db "See, told you 0 < 0xFF", 0xA, 0
bad2:   db "Wait, 0 >= 0xFF?", 0xA, 0
