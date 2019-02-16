#include <Wire.h> // must be included here so that Arduino library object file references work
#include <RtcDS1307.h>
RtcDS1307<TwoWire> Rtc(Wire);
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, D1, D2);
char timeline[16];
#include <Wire.h>
#include <Adafruit_MCP23017.h>
Adafruit_MCP23017 mcp;
void setup() {
  Serial.begin(57600);
  Serial.print("compiled: ");
  Serial.print(__DATE__);
  Serial.println(__TIME__);
  lcd.begin();
  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  Serial.println();
  Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low); 
  mcp.begin();  
  mcp.pinMode(7,OUTPUT);
  mcp.pinMode(9,OUTPUT);
  mcp.pinMode(10,INPUT);
  mcp.pullUp(10,HIGH);
  
  pinMode(D5,INPUT);
  pinMode(D6,INPUT);
}
int cout = 0 ;
void loop() {

    if (!Rtc.IsDateTimeValid()) 
    {
        Serial.println("RTC lost confidence in the DateTime!");
        lcd.print("RTC lost confidence in the DateTime!");
    }
    RtcDateTime now = Rtc.GetDateTime();
    //Times(now);
   if(mcp.digitalRead(10) == 0 ){
  Pumoff();
   soon();
  }
  if(mcp.digitalRead(10)!= 0 ){
  sooff();
  Pumon();
  }
 
    delay(1000);
    
}
int x=0;
void Times(const RtcDateTime& dt){
  lcd.clear();
   sprintf(timeline,"  %0.2d : %0.2d : %0.2d",dt.Hour(), dt.Minute(), dt.Second());
  lcd.print(timeline);
  
}

