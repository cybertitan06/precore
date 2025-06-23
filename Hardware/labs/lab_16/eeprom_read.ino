/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
#include <EEPROM.h>

int counter = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  while (!Serial){
    ;
  }
}

void read_EEPROM() {
   
    if(counter > 0){
      return;
    }
    
    for(int address = 0; address < EEPROM.length() + 1; address++){
    byte value = EEPROM.read(address);
    Serial.print("Address: ");
    Serial.print(address);
    Serial.print(", Value: ");
    Serial.print(value);
    Serial.print("\n");
    //delay(1);
  }
  counter ++;
}
// the loop routine runs over and over again forever:
void loop() {
  read_EEPROM();
}
