; fitb2.asm - Created by Jered Tupik for Pre-Core 2022
;
; Welcome to the Fill-in-the-Blank exercises! For this group of labs, we're
; giving you code that already has most of the functionality already
; implemented, we just want you to fill in the blank spots to get everything
; all tied together. Some of these labs will tie together, so you might find
; yourself copying previous code.
BITS 32

section .text
global  main
extern  printf


main:
    
    mov     esi, arr
    ; This lab is a continuation of fitb1.asm, where we'd like you to
    ; work on improving our goal-checking routine so that it isn't
    ; as much copy-paste work (which leaves more room for errors and forgetting
    ; the value used in a register). You should hopefully be familiar
    ; with the concept of a 'for' loop from Python and C, so here you'll
    ; be filling out the components of a basic loop for this lab.
    ;
    ; NOTE: There will be a couple of instructions not yet presented in
    ; this code, but don't worry about them for now. They'll be introduced
    ; tomorrow in more detail.

    ; 1) Copy your code from fitb1.asm to initialize arr to the correct
    ; values.

    mov     edi, goal_arr
    ; 2) Initialize the loop counter (ecx) to the value stored in the memory
    ; variable ctr

check_loop:
    ; 3) Check if the loop counter has gone through all the entries in the list
    
    ;je      good - Uncomment this once you've got 3 done

    ; 4) Save the current value of ecx to ctr
   
    
    ; All that good number-checking stuff 
    mov     ebx, [edi]
    push    ebx
    push    dword [esi]
    push    ecx
    push    at_expected
    call    printf
    add     esp, 16
    cmp     [esi], ebx
    jne     bad
   
    ; 5) Restore the value of ecx from memory (printf clobbered it, more on
    ; that later), and then increment ecx by 1 and esi and edi to the next
    ; index

    jmp     check_loop
 
good:
    push    success
    jmp     exit
bad:
    push    failure
exit:
    call    printf
    add     esp, 4
    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
ctr:        dd 0
at_expected:db "Value at offset %d is %d, expected %d", 0xA, 0
goal_arr:   dd 255, 01337, 2022, 0x2021, 10101010b
success:    db "Looks like everything checks out!", 0xA, 0
failure:    db "Hmm, something doesn't check out", 0xA, 0

section .bss
arr:        resd 5
