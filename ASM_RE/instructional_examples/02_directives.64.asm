BITS 64
global main

clear:
; prologue
    push rbp
    mov rbp, rsp

; Clear out the stack so we have a clean view
    mov qword [rsp+16], 1
    mov qword [rsp+24], 2
    mov qword [rsp+32], 3
    mov qword [rsp+40], 4
    mov qword [rsp+48], 5
    mov qword [rsp+56], 6
    mov qword [rsp+64], 7
    mov qword [rsp+72], 8
    mov qword [rsp+80], 9

; epilogue
    leave
    ret

main:
    call clear
; Demonstrate directives

; Known sizes do not need explicit directives!
    mov rbx, 0xdeadbeefdeadbeef
    mov [rsp], bl
    mov [rsp], bx
    mov [rsp], ebx
    mov [rsp], rbx

    nop
    nop

; Ambiguous sizes DO need explicit directives!
    mov qword [rsp], -1
    mov byte [rsp], 1

    nop
    nop

    mov qword [rsp], -1
    mov word [rsp], 2

    nop
    nop

    mov qword [rsp], -1
    mov dword [rsp], 3

    nop
    nop

    mov qword [rsp], -1
    mov qword [rsp], 4

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
