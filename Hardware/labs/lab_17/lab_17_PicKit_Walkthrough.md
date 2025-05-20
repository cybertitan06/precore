# 0x17 - Blink an LED again

## Solution:

- [Solution](solution/solution.md)

## Resources:

- Follow the [setup instructions](../../syllabus.md#setup) from the syllabus if not done already

- You should have the following installed:

  - [MPLABX IDE](https://microchipdeveloper.com/install:mplabx-lin64)
    - [Installation Guide](https://microchipdeveloper.com/mplabx:installation)
  - [MPLABX IDE Dependencies](https://microchipdeveloper.com/install:mplabx-lin64)
  - [XC8 Compiler](http://www.microchip.com/mplabxc8linux)
    - [Installation Guide](https://www.microchipdeveloper.com/xc8:installation)

- General Resources:

  - [PIC16 Pin Diagram](http://ww1.microchip.com/downloads/en/DeviceDoc/41287D.pdf)
  - [PIC16 Architecture](http://ww1.microchip.com/downloads/en/DeviceDoc/41291F.pdf)
  - [PICKIT 4 Programmer User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/50002721A.pdf)
  - [PICKIT 4 Programmer User Manual](https://microchipdeveloper.com/pickit4:start)
  - [XC8 Compiler User Manual](http://ww1.microchip.com/downloads/en/devicedoc/50002053g.pdf)
  - [XC8 Compiler Delays](resources/XC8_delay.pdf)

## Objective

Starting fresh with a new microcontroller, use the available documentation and tools to:

- Apply learned knowledge of basic electronic components and previous microcontrollers
- Develop & implement a basic program (light an LED)
- Understand basic low-level timer operation
- Using the IDE as a guide, understand the 'C'-like underpinnings of microprocessor IDEs

You will be bread-boarding the following microprocessor from your lab kit:

![pinout](resources/pinout.png)

## Steps:

### 0. Install development tools:

See `Resources` section above for this.

### 1. Get started with the IDE:

1. Open MPLABX IDE (search for `mplab` in your VM):

![example1](resources/example1.png)

2. Connect the PICKIT 4 to your VM using the USB micro cable:

![example2](resources/example2.jpg)

3. Confirm the IDE recognizes the device (look to the bottom right corner of the IDE):

![example3](resources/example3.png)

2. Start a new project (File > New Project > Microchip Embedded > Standalone Project)

3. In the new project window, select the `Mid-Range 8-bit MCUs` & find your PIC chip model number in the `Device` drop down. Then specify your PICKIT 4 programmer in the `Tool` dropdown:

![example4](resources/example4.png)

4. Select the XC8 compile you installed & specify the location/name of your project in the final window:

![example5](resources/example5.png)

### 2. Setup your breadboard with a basic circuit and connect the PICKIT 4:

**NOTE:** Be gentle inserting the PIC microprocessor into the breadboard! If you break the chip, the TAs will be <u>mad</u> at you!

Use your prior knowledge of blinking LEDs on an Arduino and build a blink circuit on one of the I/O pins:

1. Identify an I/O pin to use in the PIC chip (see the **Resources** section for a pinout diagram)
  - Which physical pin (e.g. 1-28) is it on the chip? ________
  - What is the pin label in the datasheet (e.g. CLK1/TST0, etc.) _________
2. There are 7 possible pins on the end of the PICKIT 4. Use the PICKIT 4 datasheets/guides in the **Resources** section and connect the PICKIT 4 to the chip on the breadboard
  - You **WILL** need to add other components to the breadboard for the programmer to connect correctly!
  - Do **not** wire up the V<sub>ss</sub> and V<sub>dd</sub> pins from the PICKIT 4 to the PIC chip yet!
  - _Remember V<sub>ss</sub> = V<sub>ee</sub> = LOW and V<sub>dd</sub> = V<sub>cc</sub> = HIGH_

### 3. Write a basic program to turn on your GPIO pin:

1. Based on that pin you selected to control your LED, how many pin modes can the pin be configured for? ________
2. Based on the pin you selected, what register/bit(s) do you need to set to configure it as an output to drive the LED? ________
3. What **memory address** maps to that register/bit(s)? _______
4. What register controls the **pin direction** of your GPIO register? _______
5. Which bit in this register controls your specific GPIO pin? _______
6. Using what you know, create a new **main** C source file (File > New File) and wire some basic C code that will turn on your GPIO pin using this address

### 4. Test your connection:

1. Make sure your build environment is okay by compiling your C code (Production > Build Main Project) & look for the `BUILD SUCCESSFUL` message:

![example6](resources/example6.png)

2. Navigate to File > Project Properties > PICKIT 4 and in the dropdown, select Power. Then ensure output power is selected for the programmer. **MAKE SURE YOU SELECT `APPLY` BEFORE EXITING**. Also, selecting a **5v** operating range will work fine:

![example7](resources/example7.png)

3. Navigate to Window > Target Memory Views > Configuration Bits to bring up a GUI window that configures useful registers. Make sure the output matches the following so the PIC processor clock is driven by the **internal oscillator**:

![example8](resources/example8.png)

4. Select the `Generate Source Code to Output` button to create `#pragma` statements to configure the PIC when programming. Copy and paste these into your source code.

5. Select Production > Make and Program Device Main Project. You should see the following:
  - **NOTE:** Wire up the V<sub>ss</sub> and V<sub>dd</sub> pins from the PICKIT 4 to the PIC chip at this point

![example9](resources/example9.png)

6. Using your multimeter, make sure there is a positive voltage on your GPIO pin (should be approximately 3.7v)

### 5. Blink an LED:

1. Wire up an LED **and a current limiting resistor** to your GPIO pin to see it light up
2. How do you implement a `delay()` function on the PIC chip (see **Resources** section for hints)?
3. Add a `delay()` function to toggle the LED at 0.5 second intervals in an infinite loop (LED flashes every second)

![solution](solution/solution.gif)

## `H@k3rm@n` Challenge:

**WARNING:** These problems are at the `H@k3rm@n` level. They are not required.

### 1. Time is Relative

Use a 555 timer circuit as the input clock source for the PIC instead of the internal oscillator so you can vary the LED flashing frequency manually at runtime to "visually" see the CPU clock rate.

- [Solution](solution/hackerman.md)
