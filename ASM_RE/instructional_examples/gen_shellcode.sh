#!/bin/bash

# Generate shellcode from .<arch>.asm files.

# uncomment for debugging:
#set -euxo pipefail

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <FILE>"
  exit 1
fi

FILE=$1

# Parse the final program name and the architecture from the input file
PROGRAM_NAME=$(echo "$FILE" | cut -d'.' -f1)
ARCH=$(echo "$FILE" | cut -d'.' -f2)


# build an object file with nasm such as `nasm -felf32 -F dwarf mov.32.asm` - this will produce `mov.32.o`
nasm -felf$ARCH -F dwarf $FILE

# Produce shellcode from the object file such as `objdump -S -O binary -j .text XX_reverse_shell.64.asm XX_reverse_shell.shell`
objcopy -S -O binary -j .text "$PROGRAM_NAME.$ARCH.o" "$PROGRAM_NAME.shell"

# delete the unneeded object file
rm "$PROGRAM_NAME.$ARCH.o"
