# Easier Gadget Lab

The purpose of this is to introduce the idea of exploiting binaries who have NX bit security protection

# Building

The following commands can be used to build the binary meant to be exploited. The final binary will be ./bin/gogogadget

```bash
mkdir build
cd build
cmake .. -DTARGET_ARCH=32
make
```

Try exploiting it when it is compiled for a 32-bit system. If you've gotten that down, try building it for 64-bit

```bash
mkdir build
cd build
cmake .. -DTARGET_ARCH=64
make
```

