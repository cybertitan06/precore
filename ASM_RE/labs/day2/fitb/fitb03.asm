; fitb3.asm - Created by Jered Tupik for Pre-Core 2022
;
; These are going to be some relatively free-form fill-in-the-blank
; labs, so best of luck!
[BITS 32]

section .text
global  main
extern  printf

struc _magic
    .mag1:  resd    1
    .mag2:  resd    1
    .mag3:  resd    1
    .mag4:  resd    1
endstruc


; Here's a pseudo-capstone to finish things off that should
; be doable with everything you've done for today's labs so far
; Combining function call structures and complex instructions,
; your goals for this lab are:
;
; 1) Implement the body of memset, which should follow
; stdcall procedure and perform an equivalent functionality
; to the C memset.
;
; 2) Using my_memset, zero out the _example structure created
; in this lab
;
; 3) Implement charat, a stdcall function taking in a string and
; character and determining the first index it exists at or returning
; -1 otherwise.
;
; 4) Implement charcount, a stdcall function taking in a string and
; character and counting the number of occurences in the string.
;
; Best of luck!

; memset(addr, value, len) - [addr:addr+len] = value. 
memset:

; charat(string, char) - 1st index of char in string or -1
charat:

; charcount(string, char) - Number of occurences of char in string
charcount:

main:

    ; Zero out the _example structure

    ; DO NOT EDIT BELOW THIS LINE
    cmp     dword [_example + _magic.mag1], 0
    jne     memset_fail
    cmp     dword [_example + _magic.mag2], 0
    jne     memset_fail
    cmp     dword [_example + _magic.mag3], 0
    jne     memset_fail
    cmp     dword [_example + _magic.mag4], 0
    jne     memset_fail
    push    good1
    call    printf
    add     esp, 4

    push    'v'
    push    str1
    call    charat
    mov     ebx, eax
    push    str1
    push    eax
    push    'v'
    push    ca_fmt
    call    printf
    add     esp, 16
    cmp     ebx, 9
    jne     charat_fail
    push    good2
    call    printf
    add     esp, 4

    push    'm'
    push    str1
    call    charcount
    mov     ebx, eax
    push    str1
    push    eax
    push    'm'
    push    cc_fmt
    call    printf
    add     esp, 16
    cmp     ebx, 4
    jne     charcount_fail
    push    good3
    call    printf
    add     esp, 4
    jmp     exit
    
memset_fail:
    push    bad1
    jmp     exit
charat_fail:
    push    bad2
    jmp     exit
charcount_fail:
    push    bad3
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80
    

section .data
str1:   db "I am the very model of a modern major-general", 0xA, 0

ca_fmt: db "%c is at index %d in '%s'", 0xA, 0
cc_fmt: db "%c occurs %d times in '%s'", 0xA, 0

good1:  db "Looks like the memset cleared everything!", 0xA, 0
bad1:   db "Something in the memset didn't clear out...", 0xA, 0
good2:  db "charat looks good to me!", 0xA, 0
bad2:   db "charat didn't get the right result there...", 0xA, 0
good3:  db "charcount looks good to me!", 0xA, 0
bad3:   db "charcount didn't get the right result there...", 0xA, 0

_example:
    istruc _magic
        at _magic.mag1,     dd 2022
        at _magic.mag2,     dd 2021
        at _magic.mag3,     dd 0x42
        at _magic.mag4,     dd 1
    iend
