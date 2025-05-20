; extra3.asm - Created by Jered Tupik for Pre-Core 2022
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

; Now that you've dippped your toes in the water with the previous lab, 
; why don't we try taking it a step further with something more practical?
; Try writing up a no-NULL and PIE that will open up a reverse shell on
; the local port 13337. The machine has nc installed, so try using that.
; You can also confirm if your program works by executing 'nc 127.0.0.1 13337'

_start:
