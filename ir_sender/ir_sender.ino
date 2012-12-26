#include <IRremote.h>

/*
 * ir_sender: Transmits IR signals to devices.
 * Based on IRsendDemo by Ken Shirriff (http://arcfn.com)
 * Copyright 2012 Polychronis Ypodimatopoulos
 * http://polychronis.gr
 */


IRsend irsend;
char incomingByte;
long int ircode;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    
    Serial.print("TIMER_PWM_PIN ");
    Serial.println(irsend.debug());
    
    if (incomingByte == 't') {
      ircode = 0x20DF10EF;
      sendCode(ircode, incomingByte);
    }
    
    if (incomingByte == 'y') {
      ircode = 0x7E8154AB;
      sendCode(ircode, incomingByte);
    }
      
    if (incomingByte == 'u') {
      ircode = 0x5EA158A7;
      sendCode(ircode, incomingByte);
    }
    
    if (incomingByte == 'd') {
      ircode = 0x5EA1D827;
      sendCode(ircode, incomingByte);
    }
    
    if (incomingByte == 'o') {
      ircode = 0x20DF10EF;
      sendCode(ircode, incomingByte);
      ircode = 0x7E8154AB;
      sendCode(ircode, incomingByte);
    }
  }
}

void sendCode(long int ircode, char key)
{
  for (int i = 0; i < 3; i++) {
    irsend.sendNEC(ircode, 32);
    Serial.print(key);
    Serial.println(ircode, HEX);
    delay(40);
  }
}
