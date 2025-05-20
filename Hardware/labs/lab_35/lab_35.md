# 0x35 - Data Transfer Challenge

## Solution:

- [Solution](solution/solution.md)

## Resources:

- Follow the [setup instructions](../../syllabus.md#setup) from the syllabus if not done already.

## Objective:

Imagine a scenario where you have a device running an embedded Linux OS, but it either doesn't have networking enabled or you cannot enable networking (e.g. a firmware upgrade gone wrong). Fortunately, for you, the UART interface still works.

Hack together a way to transfer data/files to the Raspberry Pi 3 B+ through the initial access if the UART interface.

## Steps:

0. "Reset" your Pi by removing the `kernel8.img` binary off the `boot` partition from the previous lab

1. Connect to your Pi over UART at **9600 baud** using the Bus Pirate (see previous labs for guidance/reference)

2. Cross-compile your "Hello World" ARM binary (**dynamically linked**) for the Pi and emulate it with QEMU to verify it works (see previous labs for guidance/reference)

3. Write some software to transfer your cross-compiled binary to the Pi over UART (you _may_ need to disconnect your UART shell with the Bus Pirate during this transfer depending on your solution)

4. Run your binary on the Pi and verify it works on target!

### Hints:

- When using the bus pirate in bridge mode with flow control (macro `(3)` under UART), the Bus Pirate is buffering the faster interface to your computer (115200 baud) for the slower baud rate communication between the Raspberry Pi (9600 baud). To get around this limitation, you will need to setup the Bus Pirate in "Transparent bridge" mode and change the Bus Pirate's baud rate to match your target. [Dangerous Prototypes' documentation](http://dangerousprototypes.com/docs/UART) on the bus pirates UART modes would be a good place to start researching ...

- You will need to think of an encoding scheme to transfer your bytes since your UART connection is a standard BASH shell prompt on the Pi

- Most serial programs expect data to be chunked so you will need a way to "re-create" your data on the target from "chunks"

- Some technologies to take a look at here are: PySerial, screen, minicom, XMODEM, YMODEM, and ZMODEM
