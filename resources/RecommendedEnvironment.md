# Recommended items to install

Here is a list of commands to install suggested items using the `apt` package manager.

```
sudo apt install build-essential gcc-multilib yasm vim wireshark ghex tmux nmap virtualenv openjdk-17-jdk
sudo dpkg --add-architecture i386 
sudo apt-get install binwalk screen minicom xxd gcc-avr binutils-avr gdb-avr \
                     avr-libc avrdude make libc6:i386 libx11-6:i386 libxext6:i386 \
                     libstdc++6:i386 lib32z1 libexpat1:i386 wget build-essential \
                     gcc-arm-linux-gnueabihf libc6-dev-armhf-cross qemu-user \
                     qemu qemu-user-static binfmt-support bison flex ssh python3 \
                     python3-pip device-tree-compiler pkg-config ncurses-dev \
                     libssl-dev git python-is-python3 python3-serial \
                     crossbuild-essential-arm64 gcc-aarch64-linux-gnu
sudo wget -P /opt https://downloads.arduino.cc/arduino-1.8.15-linux64.tar.xz
sudo tar -xvf /opt/arduino-1.8.15-linux64.tar.xz -C /opt
sudo /opt/arduino-1.8.15/install.sh
sudo chown -R $USER:$USER /opt/arduino-1.8.15/
sudo wget -P /opt https://github.com/balena-io/etcher/releases/download/v1.5.120/balena-etcher-electron-1.5.120-linux-x64.zip
sudo unzip /opt/balena-etcher-electron-1.5.120-linux-x64.zip -d /opt
```

In addition, it is also suggested to install:
### Ghidra

`https://ghidra-sre.org`

### VSCode
`https://code.visualstudio.com`

### MPLABX IDE & MPLABXC8 8 Bit Headers
`https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide` (8 bit headers only)
### MPLAB XC8 Compiler
`https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers`

