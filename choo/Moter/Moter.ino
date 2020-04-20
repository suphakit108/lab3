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

#define MCP_LEDTOG1 1
//mcp                      
#define MCP_LEDTOG2 0

Adafruit_MCP23017 mcp;
  
void setup() {  
  mcp.begin();      // Default device address 0
Serial.begin (9600);
  mcp.pinMode(0, OUTPUT);  // Toggle LED 1
    mcp.pinMode(1, OUTPUT);  // Toggle LED 1

}

void loop() {
   Serial.println("Start");
   
  mcp.digitalWrite(MCP_LEDTOG2, 1023);
  mcp.digitalWrite(MCP_LEDTOG1, 0);
  
  delay(1000);

  mcp.digitalWrite(MCP_LEDTOG2, 0);
  mcp.digitalWrite(MCP_LEDTOG1, 0);
 delay(1000);
 Serial.println("DoNE");
}

