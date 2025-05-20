; debug03.asm
;
; By now you probably know the drill, so let's get on with fixing up
; some buggy code to get some results!
[BITS 64]

section .text
global  main

; The code below should be executing a series of 64 bit write syscalls, but something seems off.
; The output should be:
;
; 1. Hello
; 2. World
; 3. Look at me, I can syscall!

main:
    mov rax, 4      ; 64 bit write syscall
    mov rbx, 1      ; stdout
    mov rcx, msg1   ; our buffer to print
    mov rdx, len1   ; the length of msg1
    syscall         ; execute the syscall!

    mov rax, 1      ; wait a sec... which number was the 64 bit write syscall?
    mov rdi, len2   ; I think the count argument goes here
    mov rsi, msg2   ; And this is definitely the buffer to write
    mov rdx, 1      ; which means this should be stdout
    syscall         ; execute the syscall??

    mov rax, msg3   ; maybe the buffer goes in rax?
    mov rdi, 1      ; and the syscall number goes here?
    mov rsi, len3   ; and the count here?
    mov rdx, 1      ; which means stdout goes here
    syscall         ; I think I got it this time

section .data
msg1:    db "1. Hello", 0xa, 0
len1:    equ $-msg1

msg2:    db "2. World", 0xa, 0
len2:    equ $-msg2

msg3:    db "3. Look at me, I can syscall!", 0xa, 0
len3:    equ $-msg3
