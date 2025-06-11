; debug6.asm - Created by Jered Tupik for Pre-Core 2022
;
; The code below compiles correctly, but seems to have a couple
; bugs that need ironed out. Any chance you can take a look at it?
; We're just adding to some memory parts we haven't used before
[BITS 32]

section .text
global  main
extern  printf

main:
    ; IGNORE THIS SECTION
    mov     dword [num1], 0xABCDEF64
    mov     dword [num2], 0x34563456
    ; IGNORE THIS SECTION
 
    mov     word [num1], 0x2022
    mov     byte [num2], 0x42

    mov     eax, bad           
    cmp     word [num1], 0x2022
    jne     done
    cmp     byte [num2], 0x42
    jne     done
    mov     eax, good

done:
    push    eax
    call    printf
    add     esp, 4

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
good:   db "num1 and num2 look all good!", 0xA, 0
bad:    db "Hmmm, num1 and/or num2 isn't what I expected them to be.", 0xA, 0

section .bss
num1:   resd 4
num2:   resd 4
