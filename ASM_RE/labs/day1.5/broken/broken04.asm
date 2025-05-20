; broken4.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got some code that, for whatever reason, isn't able to compile
; correctly. We can't understand the errors, but perhaps all you big-brained
; people can figure it out and get it working? 
[BITS 32]

section .text
global  main
extern  printf


; Now that you've learned about the jump instruction, why don't we try
; jumping all around the place? It's good for code obfuscation if you're
; not just tracing along the progress in any case.

main:
    jmp     IILLLL
IIIIII:
    mov     eax, 10
    cmp     eax, 10
    jeq     LIIILL
ILILIL:
    jnz     ILILII
IILLLL:
    mov     eax, 100
    mov     ebx, 20
    cmp     eax, ebx
    jgl     LLLLLL
LLLLLL:
    mov     eax, 0x00000001
    add     eax, 0
    jus     ILILIL
ILILII:
    xor     ecx, ecx
    jecxz   LIIIII
LIIILL:
    push    doozy    
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
doozy:  db "Hopefully that wasn't too much of a doozy.", 0xA, 0
