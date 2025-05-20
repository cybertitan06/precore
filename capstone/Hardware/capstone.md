# Pre-CORE Hardware Capstone

## Background
The capstone target network belongs to an organization that, among other things, produces SCADA/ICS hardware for manufacturing companies. One of their products is actually just an ESP32 development board with software that allows it to create a wireguard tunnel into their cloud infrastructure and offload sensor data. However, this organization refuses to distribute wireguard configurations over a network, instead preferring to send their customers custom "authentication chips", which are really just PIC16F882 microntrollers pre-loaded with the configuration file.

We have recovered countless authentication chips, however the lock bit is enabled and despite knowing that the chips interact over a SPI interface at 1MHz, we have never successfully recovered a configuration. Luckily a recent close access operation recovered one of these authentication chips and its paired ESP32 development board. We believe that this will be enough to obtain the configuration from the PIC microcontroller so that you can gain access to the organization's infrastructure.

## Engineering
Our hardware engineering team wants to remind you that we only have one authentication chip and one ESP32 development board, so it's critical that you pay close attention to the device datasheets, and not break them. If you have any questions about whether something will damage a device, you should ask. The engineers also note that the PIC is conveniently able to operate on a 3.3V supply, which can be obtained directly from the ESP32, meaning that it is not necessary to wire up a PICKit 4 programmer for power.

Additionally, our engineers wanted to point out that these PICs are really limited devices. Which means that if you figure out how to interact with it and encounter any encryption, it's likely just an XOR encryption since there isn't really enough space for anything more secure.

## Reference
You may find it helpful to refer to lab 0x17, 0x18, 0x19 and 0x20 material for a refresher on using the PIC, ESP32 and Bus Pirate.

Additional references:
- [PIC Datasheet](./resources/PIC%20datasheet.pdf)
- [ESP32 PICO KIT](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-pico-kit.html#)
- [Bus Pirate 101](http://dangerousprototypes.com/docs/Bus_Pirate_101_tutorial)
- [CyberChef](https://gchq.github.io/CyberChef/)