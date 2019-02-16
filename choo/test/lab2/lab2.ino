#include "HX711.h"
#include <Wire.h>
#include <Adafruit_MCP23017.h>  
#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS1307.h>
//=====================================
float calibration_factor =47247.00; 
#define zero_factor 88818
#define DOUT  D7
#define CLK   D8                   
#define DEC_POINT  2
float offset=0;                             //น้ำหนัก
float get_units_kg();
HX711 scale(DOUT, CLK);
//=====================================
const int analogIn=A0;//วัดกระเเส
int RawValue;
//=====================================
#define MCP_LEDTOG1 1   //mcp                      
#define MCP_LEDTOG2 0
Adafruit_MCP23017 mcp;
//=====================================
RtcDS1307<TwoWire> Rtc(Wire);
#define countof(a) (sizeof(a) / sizeof(a[0])) // time 
    char datestring[20];
//=====================================

void setup() 
{
  Rtc.Begin();
  mcp.begin();      // Default device address 0
  mcp.pinMode(MCP_LEDTOG1, OUTPUT);  // Toggle LED 1
  mcp.pinMode(MCP_LEDTOG2, OUTPUT);  // Toggle LED 2
  Serial.begin(115200);
  Serial.println("Load Cell");
  scale.set_scale(calibration_factor); 
  scale.set_offset(zero_factor);   
}
float eat=2,Kg=2,OldKg;
void loop () {
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Chlktime(now);
  kg();
  Serial.print("eat = ");
  Serial.println(eat);
  Serial.print("OldKg = ");
  Serial.println(OldKg);
  Serial.print(OldKg-get_units_kg());
  Serial.print(" = ");
  Serial.println(Kg);
  if(eat==1){
    Eat();
  }
  delay(1000);
}
void Eat(){
  Serial.println("กิน");
  if(OldKg-get_units_kg()>Kg){
    MoterOFF();
    eat=0;
    Serial.println("อิ่ม");
  }
  if(analogRead(analogIn)<800){
    MoterOFF();
    delay(1000);
    MoterRE();
    delay(1000);
    MoterNO();
    delay(1000);
    MoterOFF();
    MoterNO();
    
  }
}

