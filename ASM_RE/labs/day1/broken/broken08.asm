; broken8.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're just want to print out a short little message to the user
[BITS 32]

section .bss
global  main
extern  printf

main:
    push    str
    call    printf
    add     esp, 4

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .text
str:    db "Hope y'all are having fun so far!", 0xA, 0
