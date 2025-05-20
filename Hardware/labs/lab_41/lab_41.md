# 0x41 - FPGA Programming

**WARNING:** These problems are at the `H@k3rm@n` level. They are not required.

## Solution:

- [Solution](solution/solution.md)

## Resources:

- [Verilog TestBenches](resources/testbench_tutorial.pdf)
- [iVerilog/GTKwave Tutorial](resources/iVerilogTutorial.pdf)
- [iVerilog Documentation](https://iverilog.fandom.com/wiki/Main_Page)
- [Online Verilog Simulation](https://www.tutorialspoint.com/compile_verilog_online.php)

## Objective:

Imagine you work for some company that is trying to reverse engineer a PCB that is needed for some super secret technology contract. The PCB generates some data and transmits it using RF (think lab 0x40). Your office captured the RF traffic from this PCB, but after analyzing it, it looks encrypted... To make this even **more** complicated, the PCB is using an FPGA to generate the RF traffic so trying to dump firmware or use advanced hardware imaging techniques is not feasible here...

_However_, someone from another office in your company comes by your desk and says they "found" some interesting FPGA design files for this PCB while they were assisting in some secret offsite operation that may help out your office in their quest...

Your task in this lab is to **review these documents to reverse engineer the encryption algorithm used by the FPGA to encrypt the RF traffic**.

## Setup:

This lab requires simulation of Verilog code and visualization of waveform diagrams. Install the following software into your Ubuntu VM to complete this lab:

```bash
sudo apt install iverilog gtkwave
```

## Problem:

Download the following interesting design files:

- [`encryptor.pdf`](resources/encryptor.pdf): A black-box diagram for an interesting Verilog FPGA module used on the target PCB
- [`encryptor.obf.v`](resources/encryptor.obf.v): A obfuscated version of the Verilog FPGA module in `encryptor.pdf`

Using the above files, build a testbench in Verilog that connects to `encryptor.obf.v` using the pinout from `encryptor.pdf`. Then simulate this testbench using [iVerilog](http://iverilog.icarus.com/home) to probe the interesting FPGA module in order to figure out what encryption scheme the RF PCB is using.

## Hints:

- If you are new to Verilog, iVerilog or testbenches, review the documents in the _Resources_ section first

- To use [iVerilog](http://iverilog.icarus.com/home) with `encryptor.obf.v` and your Verilog testbench (let's say its called `testbench.v`), use the following workflow:

```bash
iverilog -o my_test.vvp encryptor.obf.v testbench.v # link your testbench to the target module
vvp my_test.vvp # simulate your testbench against encryptor.bin
gtkwave my_test.vcd # view the waveforms from the test
```

- Viewing the waveforms in GTKwave can really help with this lab!

- The point of this lab is to write a testbench, **not to try and de-obfuscate the Verilog**. But, you are a `h@k3rm@n` so feel free to attempt this route ...

## n00b Hints:

- If you need _more_ help (you are a `h@k3rm@n` right?), use the following Verilog testbench template:

```verilog
`timescale 10ns / 1ns // time unit is 10 ns with 1ns precision

module my_testbench();

  // Unit Under Test (UUT) inputs & outputs from PDF:
  reg clock;
  reg reset;
  reg enable;
  wire [7:0] data_in;
  wire [7:0] data_out;

  // UUT instantiation:
  encryptor uut (
    .clock(clock),
    .reset(reset),
    .enable(enable),
    .in(data_in),
    .out(data_out)
  );

  // generate the clock signal for the test
  initial begin
    clock = 1'b0;
    forever begin
      #1;
      clock = ~clock;
    end
  end

  // perform the test
  initial begin
    // generate waveform dump of signals during test
    $dumpfile("my_test.vcd");
    $dumpvars(0,my_testbench);
    // reset the module
    reset = 1'b1;
    #6; // wait 3 time cycles
    reset = 1'b0;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // TODO: fill in testing here...
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // end simulation of target module
    $finish;
  end

endmodule
```
