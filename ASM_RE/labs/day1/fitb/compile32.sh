#!/bin/bash

# Parse broken example filenames and compile

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


# build an object file 
nasm -g -felf32 $PROGRAM_NAME.$ARCH

# Compile an executable from the object file with gcc
gcc -no-pie -m32 -g -z noexecstack -o $PROGRAM_NAME "$PROGRAM_NAME.o"

# delete the unneeded object file
rm "$PROGRAM_NAME.o"



