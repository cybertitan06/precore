# 0x03 - Reading a Datasheet

## Solution:

Solution is shown by completing the lab steps.

## Resources:

- 555 Timer IC Dip-8 [datasheet](resources/na555.pdf)
- Capacitor (correct value should be in your kit)

## Objective

Fully define and build the following schematic of using the **A-STABLE** mode of a 555 Timer IC to blink an LED:

![01-schematic](resources/01-schematic.png)

## Steps

### 1. Calculate the Value of the Current Limiting Resistor (R<sub>3</sub>):

In order to observe the function of the 555 Timer circuit, we will be adding an LED to output signal to give a visible representation of what is going on. Referring to the data sheet, identify the function and determine the voltage of pin 3:

**pin3** = ___________________

**V<sub>pin3</sub>** = ___________________

Using what you learned in Lab 01, calculate the value of **R<sub>3</sub>** needed to limit the current to the LED (**D<sub>1<sub>**):

**R<sub>3</sub>** = ___________________

### 2. Define the Value of R<sub>1</sub> and R<sub>2</sub> Based on C<sub>1</sub>:

Refer to the section of the datasheet on "A-stable Operation" and choose a set of resistor values for **R<sub>1</sub> and R<sub>2</sub>** that will compliment the value of your capacitor **C<sub>1</sub>**:

The goal is to have the output frequency low enough to be seen. Anything below 30 Hz should work.

**Calculated Frequency** &ap; __________________ Hz

### 3. Assemble the Circuit:

Start By wiring your breadboard with **V<sub>CC</sub>** (5V) and **Ground**:

**NOTE:** I have added jumpers to the bottom rails to simplify the construction of the circuit

![02-wiring_vcc_and_ground](resources/02-wiring_vcc_and_ground.png)

Place the 555 dip-8 IC middle of the breadboard so that pin one is in the lower half of the breadboard and pin 8 is in the top spanning the middle isolation gap:

![03-555_placement](resources/03-555_placement.png)

Wire up the led (**D<sub>1</sub>**) and your chosen resistor (**R<sub>3</sub>**) in series at **Pin 3**:

![04_wiring_the_led](resources/04_wiring_the_led.png)

Wire your chosen resistors for **R<sub>1</sub>** between **Vcc** and **Pin 7.** Wire **R<sub>2</sub>** between **Pin 7** and **Pin 6.** Place a jumper wire from **Pin 6** and **Pin 2**:

![05-r1_and_r2](resources/05-r1_and_r2.png)

Add your capacitor (**C<sub>1</sub>**) with the positive side on the output of **Pin 2** and the negative side on **Pin 1**:

![06-c1](resources/06-c1.png)

Finally, connect **Vcc** to **Pin 8** and **Ground** to **Pin 1** and the Cathode of the LED (**D<sub>1</sub>**):

![07_final_wires](resources/07_final_wires.png)

**Perform any last minute continuity tests now to verify your work!**

### 4. Powering it Up:

Connect the Arduino to power (your laptop) with the USB Type-A to Type-B cable. If everything is wired correctly,  and you chose chose your resistors to tune your circuit to a visible frequency, you should see your (**D<sub>1</sub>**) blinking away:

![08_working](resources/08_working.gif)

## `H@k3rm@n` Challenge:

**WARNING:** These problems are at the `H@k3rm@n` level. They are not required.

### 1. Knock Knock

Convert your design into a **variable-tone** door bell using a piezo buzzer and a push button switch.

- [Solution](solution/hackerman.md)
