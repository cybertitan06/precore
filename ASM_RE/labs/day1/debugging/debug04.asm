; debug4.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; The following excerpt just tries to exchange values between two
; registers
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     eax, 0x01234567
    mov     ebx, 0x89ABCDEF
    
    mov     eax, ebx
    push    eax
    push    str1
    call    printf
    add     esp, 8
    
    push    ebx
    push    str2
    call    printf
    add     esp, 8
 
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:   db "EAX Value: 0x%08x", 0xA, 0
str2:   db "EBX Value: 0x%08x", 0xA, 0
