// MCP23017 Example: Slow key press reaction.
//
// Toggle LEDs and detect keypress.
//
// Example code showing slow reaction of 'button' 
// LED to keypress. Leading into why interrupts
// are useful (See next example).
//
// Copyright : John Main
// Free for non commercial use.

#include <Wire.h>
#include <Adafruit_MCP23017.h>
const int analogIn=A0;
int RawValue;

#define MCP_LEDTOG1 15

Adafruit_MCP23017 mcp;
  
void setup() {  
  mcp.begin();      // Default device address 0
Serial.begin (9600);
  mcp.pinMode(15, OUTPUT);  // Toggle LED 1

}

void loop() {
   Serial.println("Start");
  mcp.digitalWrite(15,HIGH);
  delay(1000);

  mcp.digitalWrite(15,LOW);
 delay(1000);
 Serial.println("DoNE");
}

