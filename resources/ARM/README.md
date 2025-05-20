
# ARM support for C and Assembly

Cross compilation tools must be installed for `x86` and `x86_64`

```
sudo apt update && sudo apt install gcc-x86-64-linux-gnu g++-x86-64-linux-gnu qemu-user qemu-user-static binutils-x86-64-linux-gnu binutils-x86-64-linux-gnu-dbg gcc-i686-linux-gnu build-essential gdb-multiarch
```

## Patching C build and test scripts

After install, the student can apply ARM support patches with the following command run at the root of the repo

`git apply resources/ARM/C_ARM.patch`

## Patching ASM compilation scripts

`git apply resources/ARM/ASM_ARM.patch`

The students will have to use `gdb_on_ARM.sh` in the `instructional_examples` folder. The script uses the naming for a hint on what architecture the binary is compiled for. For example, if the file is `broken01.32` then it will run the ELF with `qemu-i386` in USER mode.
