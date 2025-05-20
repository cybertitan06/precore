; broken6.asm - Created by Jered Tupik for Pre-Core 2022
;
; For some reason, we can't get the code below to work out right.
; Do you think you can take a look at it and try to get it working?
; We're trying to store ourNum inside backup for safekeeping here.
[BITS 32]

section .text
global  main
extern  printf

main:
    mov     [backup], [ourNum]
    
    mov     eax, [ourNum]
    cmp     [backup], eax
    mov     eax, success
    je      done
    mov     eax, failure
    
done:
    push    eax
    call    printf
    add     esp, 4

    xor     ebx, ebx
    mov     eax, 0x1
    int     0x80

section .data
ourNum:     dd 0x20222022
success:    db "Sucessfully backed up our important number.", 0xA, 0
failure:    db "Failed to backup our successful number.", 0xA, 0

section .bss
backup:     resd 1
