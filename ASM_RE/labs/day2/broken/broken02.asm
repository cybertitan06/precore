; broken2.asm - Created by Jered Tupik for Pre-Core 2022
;
; By now you probably know the drill, so let's get on with fixing up
; some broken code so it'll compile for us. You end result should
; be several printed statements to the screen that show
; (0xFF << 8) and (0xFF00 << 16) >> 24 in some nice printed
; statements
[BITS 32]

section .text
global  main
extern  printf

; Bit shifts are also really important instructions when you're dealing
; with stuff at the byte level, so it's good to recognize these. How
; about we show you how a few work?

main:

    ; Let's try shifting the value in the accumulator (eax) left and right
    mov     eax, 0xFF
    shl     8   ; Shift left by a byte
    push    eax
    push    0xFF
    push    sl_str
    call    printf
    add     esp, 12

    mov     eax, 0xFF00
    shl     16
    shr     24
    push    eax
    push    0xFF000000
    push    sr_str
    call    printf
    add     esp, 12

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
sl_str: db "Original: 0x%08x, Left-Shifted: 0x%08x", 0xA, 0
sr_str: db "Original: 0x%08x, Right-Shifted: 0x%08x", 0xA, 0
