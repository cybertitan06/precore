[BITS 64]

section .text
global  main

; You will be writing a program that will open a file, read the contents to 
; memory, and then write the contents in memory to stdout.  To accomplish this,
; you will need to leverage syscall instructions.  The chromium linux syscall table
; is a fantastic reference to help you with this:
;
; https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
;
; The basic goal is to open a hardcoded filename, but as a stretch goal, try to accept
; the filename as an argument from the terminal!

main:
; open syscall

; read syscall

; write syscall

exit:
; exit cleanly    

; Place any strings or other data you need here
section .data
