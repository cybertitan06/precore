BITS 64
global main

clear:
; prologue
    push rbp
    mov rbp, rsp

; Clear out the registers
    xor rax, rax
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx
    xor rdi, rdi
    xor rsi, rsi
    xor r8, r8
    xor r9, r9
    xor r10, r10
    xor r11, r11
    xor r12, r12
    xor r13, r13
    xor r14, r14
    xor r15, r15

; Clear out the stack so we have a clean view
    mov qword [rsp+16], 0
    mov qword [rsp+24], 0
    mov qword [rsp+32], 0
    mov qword [rsp+40], 0
    mov qword [rsp+48], 0
    mov qword [rsp+56], 0
    mov qword [rsp+64], 0
    mov qword [rsp+72], 0
    mov qword [rsp+80], 0

; epilogue
    leave
    ret

main:
    call clear
; Demonstrate stack operations

; We can push constant values onto the stack!
;    - Take note of $rsp
    push 1
    push 2
    push 3

; We can pop values off of the stack into registers
    pop rax
    pop rbx
    pop rcx

; We can push register values onto the stack
    push rax
    push rbx
    push rcx

; We can even push using directives to effectively dereference pointers:
    push qword [rsp]

; What happens when we push rsp?
    push rsp
    push rsp

; What about pushing ascii characters?
    mov rax, 0x6f6c6c6548
    push rax
    push rsp

; What if our string is greater than 8 characters?
    mov rax, 0x21646c726f
    push rax
    mov rax, 0x57202c6f6c6c6548
    push rax
    push rsp

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
