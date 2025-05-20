#!/bin/bash

# Parse instructional example filenames and compile

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


# build an object file with yasm such as `yasm -felf32 -g dwarf2 mov.32.asm` - this will produce `mov.32.o`
yasm -felf$ARCH -g dwarf2 $FILE

# Compile an executable from the object file with gcc such as `gcc -m32 -fno-stack-protector -fno-pie -O0 -o mov "mov.32.o
gcc -m$ARCH -fno-stack-protector -fno-pie -O0 -o $PROGRAM_NAME "$PROGRAM_NAME.$ARCH.o"

# delete the unneeded object file
rm "$PROGRAM_NAME.$ARCH.o"
