; debug4.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got a small program here that should work correctly but
; just doesn't for some reason. Maybe you can see what we're doing wrong here?
[BITS 32]

section .text
global  main
extern  printf

; If you're going to take away one thing from this course though,
; remember the call instruction. It's important and the closest thing
; we have to functions in this barren wasteland of mnemonics.

; This here is a function. We're keeping it simple here, all it does is
; setup a local str, save to it, read from it, and then print it to
; the user
my_func:
    push    ebp
    mov     ebp, esp
    sub     esp, 4
   
    ; Save the local variable
    mov     eax, f_str
    mov     [esp-4], eax

    ; Reload from it
    mov     eax, [ebp-4]
   
    ; Print it
    push    eax
    call    printf
    add     esp, 4

    ; Then clean everything up
    pop     ebp
    ret

main:

    ; You can do nifty things with calls, like print strings for the user!
    push    str
    jmp     printf
    add     esp, 4 

    ; It can be combined with cmps too for conditional function calls!
    mov     eax, 0
    cmp     eax, 1
    call    not_equal
    jmp     func_call
not_equal:
    push    ne
    call    printf
    add     esp, 4
func_call:
    ; Here's an example of a function we made ourselves!
    call    my_func
    ret 

section .data
str:    db "Hope these debugging labs haven't been too bad!", 0xA, 0
ne:     db "0 != 1", 0xA, 0
f_str:  db "Hey, I'm in a function now!", 0xA, 0
