; broken2.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got some code that, for whatever reason, isn't able to compile
; correctly. We can't understand the errors, but perhaps all you big-brained
; people can figure it out and get it working? 
[BITS 32]

section .text
global  main
extern  printf


; XCHG is such a useful little instruction, but for some reason we can't seem
; to get it to do what we want just yet. Any change you can fix our code
; to get it working? 

main:

    ; Good old-fashioned register swapping with xchg
    mov     esi, 11223344
    mov     edi, 55667788
    push    esi
    push    edi
    push    b_str
    call    printf
    add     esp, 12
    xchg    edi, esi
    push    esi
    push    edi
    push    a_str
    call    printf
    add     esp, 12

    ; We've got two values in memory we'd like to swap with each other. XCHG
    ; makes that nice and simple for us
    push    dword [num2]
    push    dword [num1]
    push    b_str
    call    printf
    add     esp, 12
    xchg    [num1], [num2]
    push    dword [num2]
    push    dword [num1]
    push    a_str
    call    printf
    add     esp, 12
   
    ; xchg can operate on 8 and 16 bit registers too, watch!
    mov     esi, 0x0123
    mov     edi, 0x4567
    push    esi
    push    edi
    push    b_str
    call    printf
    add     esp, 12
    xchg    dil, si
    push    esi
    push    edi
    push    a_str
    call    printf
    add     esp, 12

    ; Immediate values? Not a problem!
    xchg    num1, num2

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
num1:   dd 0xFEDCBA98
num2:   dd 0x76543210

b_str:  db "Before Swap: %d - %d", 0xA, 0
a_str:  db "After Swap: %d - %d", 0xA, 0
