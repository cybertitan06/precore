; broken3.asm - Created by Jered Tupik for Pre-Core 2022
;
; By now you probably know the drill, so let's get on with fixing up
; some broken code so it'll compile for us.
; Don't be scared if you end up just commenting out some code in order
; to get this working. There are some things an instruction isn't capable
; of. Ideally, the end result for this should having found the address
; of str2 and printing it to the screen. The first part remains a question
; of possibility.
[BITS 32]

section .text
global  main
extern  printf

; Intel Syntax has this somewhat covered by mov instructions, but lea can
; be invaluable on other architectures or if you just want to really
; make sure you're addressing the right location. Also, pointers.

main:

    ; Hmm, I wonder if the assembly program stores immediate values somewhere
    ; in memory. Can I check?
    lea     eax, 0
    push    eax
    push    0
    push    str1
    call    printf
    add     esp, 12

    ; In any case, it is good for getting the address of strings and other
    ; things in memory. Watch, they'll match.
    mov     eax, str2
    lea     ebx, eax
    push    ebx
    push    eax
    push    str2
    call    printf
    add     esp, 12

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
str1:   db "%d found at 0x%08x in memory. Cool.", 0xA, 0
str2:   db "String at address 0x%08x, lea found 0x%08x", 0xA, 0
