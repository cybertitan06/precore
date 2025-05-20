; broken5.asm - Created by Jered Tupik for Pre-Core 2022
;
; Same as before, we've got some code that, for whatever reason, isn't able to compile
; correctly. We can't understand the errors, but perhaps all you big-brained
; people can figure it out and get it working? 
[BITS 32]

section .text
global  main
extern  printf

; The piece-de-resistance, though, is the call function. It's the
; foundations of pretty much every non-basic assembly program. Why don't
; you take a look at it?

function_1:
    ret

funtion_2:
    call    function_1
    ret

main:
    call    function_1
    call    function_2
    
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
