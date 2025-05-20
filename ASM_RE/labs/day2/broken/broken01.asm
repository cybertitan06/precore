; broken1.asm - Created by Jered Tupik for Pre-Core 2022
;
; By now you probably know the drill, so let's get on with fixing up
; some broken code so it'll compile for us. Ideally, we'd like to
; see something like "Array @ <ADDRESS>; Length: 4" print to screen
[BITS 32]

section .text
global  main
extern  printf

struct _arraylist
    .arr:   resd    1
    .len:   resd    1
endstruct

; Structures in assembly? Well, certainly sounds better than manually
; dealing with buffers and handling that mess. Why don't we try something
; like an array with size information?

main:

    ; Initialize our struct fields
    mov     eax, arr
    mov     [my_struct + _arraylist.arr], eax
    mov     eax, [len]
    mov     [my_struct + _arraylist.len], eax

    ; Extract the fields and print out the information
    mov     eax, [my_struct + _arraylist.len]
    push    eax
    mov     eax, [my_struct + _arraylist.arr]
    push    eax
    push    str
    call    printf
    add     esp, 12

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
arr:    dd 20, 20, 20, 21
len     dd 4
str:    db "Array @ 0x%08x; Length: %d", 0xA, 0

section .bss
my_struct:
    istruct _arraylist
        at _al.arr,     resd 1
        at _al.len,     resd 1
    iend
