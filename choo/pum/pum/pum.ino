#include <Wire.h>
#include <Adafruit_MCP23017.h>
Adafruit_MCP23017 mcp;
void setup() {
      Serial.begin(9600);
      pinMode(D5,INPUT);
      pinMode(D6,INPUT);
      mcp.begin();
      mcp.pinMode(10, INPUT);
      mcp.pullUp(10, HIGH);
      mcp.pinMode(7, OUTPUT);
      mcp.pinMode(8, OUTPUT);
}
int clk=0;

void loop() {
      if(mcp.digitalRead(10) != 0){
          clk=1;  
      }
      if(clk == 1){
          PumON();
          clk=2;  
      }
        Serial.println(digitalRead(D5) + digitalRead(D6));
      if(digitalRead(D5) + digitalRead(D6) == 2 && clk == 2){
          PumOFF();
          clk=3;  
      }
      if(clk == 3){
          VoilON();
      }
      if(digitalRead(D5) + digitalRead(D6) == 0 && clk == 3){
          VoilOFF();
          clk = 0;
      }
      
      delay(1000);
}
void PumON(){
      mcp.digitalWrite(7,LOW);  
        Serial.print("Casdasdasd ");
}
void PumOFF(){
      mcp.digitalWrite(7,HIGH);  
}
void VoilON(){
      mcp.digitalWrite(8,HIGH);  
}
void VoilOFF(){
      mcp.digitalWrite(8,LOW);  
}

