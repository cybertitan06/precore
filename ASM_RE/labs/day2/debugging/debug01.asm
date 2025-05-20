; debug1.asm - Created by Jered Tupik for Pre-Core 2022
;
; By now you probably know the drill, so let's get on with fixing up
; some buggy code to get some results!
[BITS 32]

section .text
global  main
extern  printf

struc _example
    .member1:    resd    1
    .member2:    resw    1
    .member3:    resb    1
endstruc

; This here is just a simple example showing the ability to store data
; of different sizes in a structure.  Something looks off in our output, 
; can you make it match the following?
;
; member1: 0x20, member2: 0xff00, member3: 0x42424242

main:

    ; Initialize our struct fields
    mov     dword [my_struct + _example], 0x42424242
    mov     word [my_struct + _example], 0xFF00
    mov     byte [my_struct + _example], 0x20

    mov     eax, [my_struct + _example]
    push    eax
    xor     eax, eax
    mov     ax, [my_struct + _example]
    push    eax
    xor     eax, eax
    mov     al, [my_struct + _example]
    push    eax
    push    str
    call    printf
    add     esp, 16

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str:    db "member1: 0x%02x, member2: 0x%04x, member3: 0x%08x", 0xA, 0

section .bss
my_struct:
    istruc _example
        at _example.member1,   resd 1
        at _example.member2,   resw 1
        at _example.member3,  resb 1
    iend
