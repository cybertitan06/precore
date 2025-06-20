; fitb5.asm - Created by Jered Tupik for Pre-Core 2022
;
; Here you're left more to your own devices to get an implementation going that
; satisfies what we're asking for. Best of luck getting your code to work!
[BITS 32]

section .text
global  main
extern  printf

; You've seen bits and pieces of them here and there, but here we're testing
; you to create the basic assembly structures for several kind of loops. Let's ; see what you can do!

main:

    ; 1 - Create a for loop that pushes numbers 0 through 10000 to the stack

    ; 2 - Create a while loop that pops those pushed numbers to the stack and
    ; sums them, storing the result in the loop_sum variable

    ; 3 - Create a do while loop that copies the loop_sum variable to an array
    ; with a length stored in the len variable

    ; DO NOT EDIT BELOW THIS LINE
    xor     edx, edx
    mov     eax, [arr]
    add     eax, [arr+4]
    add     eax, [arr+8]
    add     eax, [arr+12]
    add     eax, [arr+16]
    mov     ebx, [loop_sum]
    div     ebx
    cmp     eax, [len]
    jne     bad_cmp
    push    good
    jmp     exit

bad_cmp:
    push    bad
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
bad:    db "Looks like one of your loops messed up somewhere. Take another look and see where it went wrong.", 0xA, 0
good:   db "Congrats, you managed to get your loops implemented!", 0xA, 0
len:    dd 5

section .bss
loop_sum:   resd 1
arr:        resd 5
