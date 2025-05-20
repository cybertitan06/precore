; broken6.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're storing a couple numbers in memory
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     [myByte], 0x42
    mov     [myWord], 0x2022
    mov     [myDword], 0x12345678
    
    mov     eax, failure
    cmp     [myByte], 0x42
    jne     done
    cmp     [myWord], 0x2022
    jne     done
    cmp     [myDword], 0x12345678
    jne     done
    mov     eax, success
    
done:
    push    eax
    call    printf
    add     esp, 4

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
success:    db "Sucessfully stored numbers in memory.", 0xA, 0
failure:    db "Something doesn't seem right in memory.", 0xA, 0

section .bss
myByte:     resb 1
myWord:     resw 1
myDword:    resd 1
