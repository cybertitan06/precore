BITS 32
global main

main:
; Zero out our registers
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx

; increment by one
    inc eax
    inc eax
    inc eax

; decrement by one
    dec eax
    dec eax
    dec eax

; Adding constants
    add eax, 1
    add eax, 2
    add eax, 3

    nop
    nop

; Subtracting constants
    sub eax, 1
    sub eax, 4

    nop
    nop

; Subtracting to zero - notice the changes to the $eflags register
    sub eax, 1

    nop
    nop

; Subtracting to -1 - notice the changes to the $eflags register and the value of $eax
    sub eax, 1

    nop
    nop

; Reset

    mov eax, 1
    mov ebx, 2
    mov ecx, 3

    nop
    nop

; Adding and subtracting using registers
    add eax, ebx
    add ebx, ecx
    sub ecx, ebx

    nop
    nop

; mul uses eax as the multiplicand and the specified value as the multiplier
; product is stored back in eax
    mov eax, 1
    mov ebx, 2
    mov ecx, 0

    mul ebx
    mul ebx

; What if we want to multiply two numbers that will result in a product greater than the
; max 32 bit integer size?  Take note of what's in eax and what's in edx after the 
; mul instruction.
   
    mov eax, 0xffffffff
    mov ebx, 2
    
    mul ebx

    nop
    nop

; imul is used for signed multiplication and can be invoked in multiple ways:
    mov ebx, 2
    mov ecx, 4
    
    imul ebx, ecx ; product is stored in ebx

    mov ecx, 0
    mov ebx, 2
    imul ecx, ebx, 4 ; product is stored in ecx

; div uses eax as the dividend and the specified value as the divisor
; quotient is stored back in eax
; remainder is stored in edx
    mov eax, 4
    mov ebx, 2
    ; xor edx, edx 
    div ebx ; EDX:EAX is divided by EBX

; We expect a remainder here - keep an eye on edx
    mov eax, 4
    mov ebx, 3
    div ebx

; divide by 0?
    mov eax, 4
    mov ebx, 0
    div ebx


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
