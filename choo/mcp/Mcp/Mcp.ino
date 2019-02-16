#include <Wire.h>
#include <Adafruit_MCP23017.h>
Adafruit_MCP23017 mcp;
void setup() {
 mcp.begin();
 mcp.pinMode(7, OUTPUT);
  mcp.pinMode(10, INPUT);
   mcp.pullUp(10,HIGH);
}

void loop() {
  if(mcp.digitalRead(10) == 0){
    mcp.digitalWrite(7,HIGH);  
  }
  if(mcp.digitalRead(10) != 0){
    mcp.digitalWrite(7,LOW);  
  }
  delay(1000);
}
