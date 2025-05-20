; fitb1.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; For this lab, we've got several numbers that we want to see zero and sign
; extended by you, as described below.
;
; GOALS:    Zero extend the first byte of num1 and store in EAX
;           Sign extend the last two bytes of num2 and store in EBX
;           Sign extend the last byte of num1 and store in ECX
;           Zero extend the first two bytes of num2 and store in EDX

main:

    ; DO NOT EDIT BELOW THIS LINE
    push    edx
    push    0x0000FF7F
    push    str
    push    ecx
    push    0xFFFFFF80
    push    str
    push    ebx
    push    0xFFFF8000
    push    str
    push    eax
    push    0x0000007F
    push    str
    call    printf
    add     esp, 12
    call    printf
    add     esp, 12
    call    printf
    add     esp, 12
    call    printf
    add     esp, 12

exit:
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
num1:   dd 0x80FFFF7F
num2:   dd 0x8000FFFF

str:    db "Expected Value: %d, Actual Value: %d", 0xA, 0
