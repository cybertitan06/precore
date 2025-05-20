; extra2.asm - Created by Jered Tupik for Pre-Core 2022
;
; In case y'all are bored or get through all the other Assembly
; labs early, here's a bit of extra content to try your hand at.
; Please note: All of the extra exercises are going to be outside
; of the scope of the material presented in the class, but they
; do have real world applications. In other words, you're going
; to need to use the Internet to do some research if you're not
; familiar with the topic. Good luck!
[BITS 32]

section .text
global  _start

; All right, let's try taking this one step further. If you take a look
; at objdump -sS extra1, you're probably going to see some NULL bytes
; or references to hard-coded addresses in there. This is something
; of a no-no when it comes to writing any shellcode. We want things
; to be nicely copied onto the stack and not expecting a hardcoded
; address in order to get things to work.
;
; So, your challenge for this lab is to take your extra1.asm code
; and modify it to include no NULL bytes or references to a hardcoded
; address. Otherwise, same goal as before. Good luck!

_start:
