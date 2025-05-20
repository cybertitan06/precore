# 0x32 - Embedded Toolchains

## Solution:

- [Solution](solution/solution.md)

## Resources:

- Follow the [setup instructions](../../syllabus.md#setup) from the syllabus if not done already.

## Objective:

Cross compile a simple "Hello World" program from your x86 Ubuntu VM that will execute on the ARM Raspberry Pi 3 B+.

## Steps:

### 1. Setup your Development Environment:

Check that your development environment is set up:

```bash
arm-linux-gnueabihf-gcc -v
```

The above command should return something _like_ the following:

```
Using built-in specs.
COLLECT_GCC=arm-linux-gnueabihf-gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc-cross/arm-linux-gnueabihf/9/lto-wrapper
Target: arm-linux-gnueabihf
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.3.0-17ubuntu1~20.04' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libitm --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --without-target-system-zlib --enable-libpth-m2 --enable-multiarch --enable-multilib --disable-sjlj-exceptions --with-arch=armv7-a --with-fpu=vfpv3-d16 --with-float=hard --with-mode=thumb --disable-werror --enable-multilib --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=arm-linux-gnueabihf --program-prefix=arm-linux-gnueabihf- --includedir=/usr/arm-linux-gnueabihf/include
Thread model: posix
gcc version 9.3.0 (Ubuntu 9.3.0-17ubuntu1~20.04)
```

### 2. Writing C:

Write some C code that prints "Hello World" to STDIO.

### 3. Compiling the Program:

Compile your file as follows:

```bash
arm-linux-gnueabihf-gcc -o hello_world hello_world.c
```

If there were no errors with the build process, you should be left with a `hello_world` binary. Verify that the file is indeed a ARM ELF file by running the following:

```bash
file hello_world
```

This should display something like the following:

```
hello_world: ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, BuildID[sha1]=89022137e63c8f8c8600eb27f974ac893b98af52, for GNU/Linux 3.2.0, not stripped
```

### 4. Compiling the Program with No Dependencies:

Add the `-static` option to the previous `gcc` command to build **everything** needed for your program **into** your program. Assuming the code is being tested on a non-ARM machine, running the binary yields the following error:

**NOTE:** If you followed the setup instructions for your Ubuntu VM, then you will get the `/lib/ld-linux-armhf.so.3: No such file or directory` error instead. This is normal since QEMU installed hooks into `/proc/sys/fs/binfmt_misc` that uses a kernel driver to instruct QEMU to _automatically_ run whenever ELF files with signatures for other architectures than the host machine are passed to the kernel runtime linker for user mode programs!

```bash
./hello_world
# bash: exec format error: ./hello_world
#   OR
# /lib/ld-linux-armhf.so.3: No such file or directory
```

Instead, the program needs to be run on the target machine or in a 32-bit ARM emulator. QEMU provides us that functionality.

### 5. Setup QEMU:

In order to emulate ARM in an x86, x64, or other environments, you can use QEMU. In this case, we have an ELF program that does not rely on low-level devices, so we can perform **user-mode** emulation. This is not to be confused with **kernel-mode** execution/emulation. This is just a program that involves basic I/O, so user-mode emulation will work just fine.

Test run the statically compiled `hello_world` file as follows:

```bash
qemu-arm hello_world
```

Since QEMU installed hooks into `/proc/sys/fs/binfmt_misc` that uses a kernel driver to instruct QEMU to run _automatically_ for different ELF header architecture signatures, you can run the following as well to run `qemu-arm` from the command line:

**NOTE:** To see all the different QEMU architecture emulators installed on your system, try running `ls -la /proc/sys/fs/binfmt_misc`

```bash
./hello_world
```

### 6. Beyond Statically-Linked Binaries:

In most embedded environments, programs don't just run in nice, monolithic, static binaries.  They use dynamic libraries. Let's build the program again with more realistic options:

```bash
arm-linux-gnueabihf-gcc -g -Wall -fPIC -o hello_world hello_world.c
```

| Command/Option             | Description |
| -------------------------: | :--- |
| `arm-linux-gnueabihf-gcc`  | GNU C cross-compiler for the armhf architecture
| `-g`                       | include the default debug information (optional)
| `-Wall`                    | enables all compiler's warning messages
| `-fPIC`                    | generates position independent code (PIC) for shared libraries
| `-o`                       | writes the build output to the given output file

Checking the output with the `file` command might yield something like this (could be different).  It might show shared object instead of executable, but the key is confirming that it's _dynamically linked_:

```
hello_world: ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, BuildID[sha1]=72f8fc43a587ef051822dbab6d53ad1337f2b543, for GNU/Linux 3.2.0, with debug_info, not stripped
```

Testing it with QEMU won't work without some help, as the loader is not found anywhere in the host operating system's path. The error might look like the following:

```bash
qemu-arm ./hello_world # /lib/ld-linux-armhf.so.3: No such file or directory
```

Find `/lib/ld-linux-armhf.so.3` somewhere on your system. Once you have found it, provide the parent directory of the `lib` folder with the `-L` option. For example, if the full path to `ld-linux.armhf.so.3` were `/usr/share/arm/lib/ld-linux.armhf.so.3`, you would provide '`-L /usr/share/arm`' as the option:

```bash
find / -name ld-linux-armhf.so.3 2>/dev/null
# ...
qemu-arm -L <FILL_ME_IN> ./hello_world
```

## `H@k3rm@n` Challenge:

**WARNING:** These problems are at the `H@k3rm@n` level. They are not required.

### 1. **Let me flash an LED or I am leaving ...**

Take your GPIO blink program from the previous challenge and add Linux socket programming to it in order to turn your blink program into an HTTP-enabled server that allows for you to blink your LED remotely.

**HINT:** You shouldn't be trying to write an HTTP server from scratch ... You should have code you can re-use or give Google a hit to find a template to use ...

**NOTE:** This challenge requires the previous 2 challenges to be complete before attempting!

**NOTE:** If you make a solution for this, let the instructors know! This one has not been done yet and your solution could become **THE** solution ;)
