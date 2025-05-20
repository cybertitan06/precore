BITS 32
global main

back_jmp:
    jmp check1  ; Can jump backwards as well as forwards

main:
    ; Zero out our registers
    xor eax, eax

    ; Demonstrate jmp/je/jne operations

    ; jmp will jump blindly to another piece of code
    mov eax, 10
    add eax, 1
    jmp back_jmp
    mov eax, 0      ; Never gets executed

check1:
    cmp eax, 11
    je  check2      ; je operates off the ZF (set means equal)    
    jmp nothing

check2:
    cmp eax, 10
    jne for_loop_start
    jmp nothing

for_loop_start:
    ; Combination of jumps useful implementing conditionals, like loops
    mov eax, 0
for_loop:
    cmp eax, 10
    je  do_loop_start
    add eax, 1
    jmp for_loop

do_loop_start:
    mov eax, 0
do_loop:
    add eax, 1
    cmp eax, 10
    jne do_loop

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
