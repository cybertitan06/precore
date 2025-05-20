BITS 32
global main

main:
    ; Zero out our registers
    xor eax, eax
    xor ebx, ebx

    ; Demonstrate flag/cmp operations

    ; cmp is equivalent to sub, without modifying the destination register
    mov eax, 10
    mov ebx, eax
    sub ebx, 9  ; Pay attention to the $eflags and ebx
    cmp eax, 9  ; Notice how $eflags doesn't change value with this cmp
                ; and eax is still the same

    ; Sets the OF (overflow) in cases of signed overflow
    mov al, -128
    cmp al, 1

    ; Sets the CF (carry) in cases of unsigned overflow
    mov al, 15
    cmp al, -1

    ; ZF (zero) is set whenever the result is zero (i.e. equal)
    mov eax, 100
    cmp eax, 100 ; Set
    cmp eax, 101 ; Unset

    ; AF (adjust) is primarily used for binary-coded decimal, 
    ; but otherwise is set when ops 2 > ops 1
    mov eax, 10
    cmp eax, 11
    cmp eax, 9

    ; SF (signed) corresponds to the MSB of the result
    cmp eax, 11 ; Set
    cmp eax, 9  ; Unset

nothing:
; A whole lot of nothing so we keep the bottom of our screen clean
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
