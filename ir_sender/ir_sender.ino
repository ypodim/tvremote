/*
 * ir_sender: Transmits IR signals to devices.
 * Based on IRsendDemo by Ken Shirriff (http://arcfn.com)
 * Copyright 2012 Polychronis Ypodimatopoulos
 * http://polychronis.gr
 */

#include <IRremote.h>

IRsend irsend;
char incomingByte;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    if (incomingByte == 't') {
      for (int i = 0; i < 3; i++) {
        irsend.sendNEC(0x20DF10EF, 32); //TV power
        delay(40);
      }
    }
    
    if (incomingByte == 'y') {  
      for (int i = 0; i < 3; i++) {
        irsend.sendNEC(0x7E8154AB, 32); //Yamaha power
        delay(40);
      }
    }
      
    if (incomingByte == 'u') {
      for (int i = 0; i < 3; i++) {
        irsend.sendNEC(0x5EA158A7, 32); //Yamaha UP
        delay(40);
      }
    }
    
    if (incomingByte == 'd') {
      for (int i = 0; i < 3; i++) {
        irsend.sendNEC(0x5EA1D827, 32); //Yamaha DOWN
        delay(40);
      }
    }
  }
}
