; debug8.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; Something weird is going on with the printf here when we try
; to print a string.
[BITS 32]

section .text
global  main
extern  printf

main:
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    inc     eax
    inc     ebx
    inc     ecx
    inc     edx
    mov     eax, str
    mov     [printf], eax
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

    push    dword [print]
    call    printf
    add     esp, 4

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:  db "You're almost at the end of the debugging exercises!", 0xA, 0

section .bss
print:  resd 4
