; broken2.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; It'll print out a nice "Hello World!" to the screen when its working,
; so see if you can get it to do that!
[BITS 32]

section .text
global  main

main:
    
    ; Print Hello World using x86 syscalls
    move    edx, len
    move    ecx, str
    move    ebx, 0x1
    move    eax, 0x4
    int     0x80

    ; Return cleanly
    xor     ebx, ebx
    move    eax, 0x1
    int     0x80

section .data

str:    db "Hello World!", 0xA, 0   ; Good old null-terminated 'Hello World!'
len:    equ ($-str)                 ; Trick for string length.
