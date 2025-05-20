; broken9.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; All we're trying to do is store in a variable called 'word'
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     word [word], 0xABCD

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .bss
word:   resw 1
