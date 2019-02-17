#include "HX711.h"

float calibration_factor =47247.00; 
#define zero_factor 88818
#define DOUT  D7
#define CLK   D8                   
#define DEC_POINT  2

#include <Wire.h>
#include <Adafruit_MCP23017.h>
const int analogIn=A0;
int RawValue;
#define MCP_LEDTOG1 1
#define MCP_LEDTOG2 0
Adafruit_MCP23017 mcp;
  
float offset=0;
float get_units_kg();
HX711 scale(DOUT, CLK);

void setup() 
{
  mcp.begin();      // Default device address 0
  mcp.pinMode(MCP_LEDTOG1, OUTPUT);  // Toggle LED 1
  mcp.pinMode(MCP_LEDTOG2, OUTPUT);  // Toggle LED 2
  Serial.begin(115200);
  Serial.println("Load Cell");
  scale.set_scale(calibration_factor); 
  scale.tare(zero_factor);   
}
void loop() 
{ 
  float num = -0.01;
  Serial.print("Reading: ");
  String data = String((get_units_kg()+offset)+num, DEC_POINT);
  Serial.print(data);
  Serial.println(" kg");
//  RawValue = analogRead(a0);
  Serial.println(RawValue);
  mcp.digitalWrite(MCP_LEDTOG2, 0);
  mcp.digitalWrite(MCP_LEDTOG1, 1023);
  delay(1000);
  if(RawValue<800){
    mcp.digitalWrite(MCP_LEDTOG2, 500);
    mcp.digitalWrite(MCP_LEDTOG1, 0);
    delay(500);
  }
  

}
float get_units_kg()
{
  return(scale.get_units()*0.453592);
}
