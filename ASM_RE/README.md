# CNODP Pre-CORE ASM/RE/Binary Exploitation Syllabus

## Course Description:
This course covers the fundamental concepts of assembly programming, reverse engineering, and binary exploitation.

## Prerequisites: 
Basic computer science principles and previous programming experience.

## Objectives:
By the end of this course, you should be able to:

- Understanding of what assembly actually is
- Write a simple x86 32 and 64 bit program in assembly
- Reverse engineer a simple compiled C binary
- Identify a vulnerability in a simple compiled C binary
- Exploit a vulnerable binary with custom written shellcode


## Lecture Slides:
- [Day 1](https://docs.google.com/presentation/d/1eDlxNswjoKjt-zbAB4XQKpFgmzF6tUd5ftTU4WWv1Ps)
- [Day 2](https://docs.google.com/presentation/d/1sDPCFFxXc3XwG8RYqh0a3Va2-VBPhiVIUrDRBqDzcrI)
- [Day 3](https://docs.google.com/presentation/d/1DfI3Ze1Ym4VICsEXcByFULelLL8wYil8BtQWKUe1qsM)
- [Day 4](https://docs.google.com/presentation/d/1BLORYiTWsDbipdzga7Nh-xm0WCSkLO_pT5zcyh27Jxk)
- [Day 5](https://docs.google.com/presentation/d/1qTu9ARca9ogseWku2VRlsyctDNNQmXeL0_NCT-7B9xo)

## Recommended Reading:
- Reverse Engineering for Beginners - Dennis Yurichev
- The Art of Assembly Language Programming - Randall Hyde
- [Smashing The Stack For Fun And Profit - Aleph One](https://inst.eecs.berkeley.edu/~cs161/fa08/papers/stack_smashing.pdf)

## Recommended Videos:
- https://www.youtube.com/watch?v=75gBFiFtAb8 (x86 Assembly Crash Course)
- https://www.youtube.com/watch?v=HgEGAaYdABA (x86 Assembly: Hello World!)
- https://www.youtube.com/watch?v=d4Pgi5XML8E (HackadayU: Reverse Engineering with Ghidra Class 1)
- https://www.youtube.com/watch?v=fTGTnrgjuGA (Ghidra quickstart & tutorial: Solving a simple crackme)
- https://www.youtube.com/watch?v=sCtY--xRUyI (introduction to GDB - Harvard CS50)

## Training Hours:
Classes are eight and a half hours, Monday through Friday, excluding federal holidays.  The student should expect to be present / available from 0800 - 1630 with the exception of lunch from 1200 - 1230. Work excusals from class (PCS items, etc…) through the class instructor and your chain of command before being absent.

| Day       | Objectives                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
|-----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Monday    | - Introductions<br/>- Understand what Assembly is and why we care about it<br/>-  Understand the importance of registers when writing Assembly<br/>- Understand a few basic instructions and how to use them<br/>- Understand how assembled programs are structured<br/>- Understand the basics of the stack and how to interface with it<br/>- Understand how to implement conditional logic in Assembly<br/>- Demonstrate your understanding through lab challenges |
| Tuesday   | - Understand the different calling conventions you may encounter<br/>- Understand how structures are represented in assembly and in memory<br/>- Understand how pointers are represented in assembly and in memory<br/>- Understand how to execute syscall instructions<br/>- Demonstrate your understanding through lab challenges                                                                                                                                                                                               |
| Wednesday | - Understand how to statically reverse engineer a binary utilizing Ghidra<br/>- Understand how to dynamically reverse engineer a binary  utilizing GDB<br/>- Demonstrate your understanding through lab challenges                                                                                                                                                                                                                                                                                                                |
| Thursday  | - Understand how to identify vulnerabilities a simple C binary with symbols and an executable stack<br/>- Understand how to exploit a vulnerable binary with custom shellcode<br/>- Demonstrate your understanding through lab challenges                                                                                                                                                                                                                                                                                         |
| Friday    | - Understand how to exploit a vulnerable binary with basic stack protections<br/>- Demonstrate your understanding through lab challenges                                                                                                                                                                                                                                                                                                                                                                                          |
