void Line_Notify(String message) ;

#include <ESP8266WiFi.h>
//#include <WiFiClientSecureAxTLS.h> // กรณีขึ้น Error ให้เอาบรรทัดนี้ออก

// Config connect WiFi
#define WIFI_SSID "Computer"
#define WIFI_PASSWORD "571733022"

// Line config
#define LINE_TOKEN "JLI3ZSVPO38RwV9Al9R366xN1uDuHBXUe8vKfzvfXVm"

//#define sw

//String message = "โดนกด"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้
#include "Adafruit_MCP23017.h"
#define pin11 0
#define pin12 1
#define pin13 2

#define pin21 3
#define pin22 4
#define pin23 5

#define pin31 6
#define pin32 7

#define pin41 8
#define pin42 9

#define pin51 10

#define pin61 11

#define pin71 12
#define pin72 13

#define pin81 14
#define pin82 15 
//
//#define Relay1 D5
//#define Relay2 D6
//#define Relay3 D7
//#define Relay4 D0

Adafruit_MCP23017 mcp;
int cout =0;
int Cutoutdoor[4];
int Cutindoor[2];
int TanKWater[2];

void Zone1();
void Zone2();
void Zone3();
void Zone4();
void Zone5();
void Zone6();
void Zone7();
void Wificonnect();

void Relay1();
void Relay2();
void Relay3();
void Relay4();
void CallLine(String message);

void setup() {
  Serial.begin(9600);
  mcp.begin();
  mcp.pinMode(pin11, INPUT);
  mcp.pullUp(pin11, HIGH);

  mcp.pinMode(pin12, INPUT);
  mcp.pullUp(pin12, HIGH);

  mcp.pinMode(pin13, INPUT);
  mcp.pullUp(pin13, HIGH);

  mcp.pinMode(pin21, INPUT);
  mcp.pullUp(pin21, HIGH);

  mcp.pinMode(pin22, INPUT);
  mcp.pullUp(pin22, HIGH);

  mcp.pinMode(pin23, INPUT);
  mcp.pullUp(pin23, HIGH);

  mcp.pinMode(pin31, INPUT);
  mcp.pullUp(pin31, HIGH);

  mcp.pinMode(pin32, INPUT);
  mcp.pullUp(pin32, HIGH);

  mcp.pinMode(pin41, INPUT);
  mcp.pullUp(pin41, HIGH);

  mcp.pinMode(pin42, INPUT);
  mcp.pullUp(pin42, HIGH);

  mcp.pinMode(pin51, INPUT);
  mcp.pullUp(pin51, HIGH);

  mcp.pinMode(pin61, INPUT);
  mcp.pullUp(pin61, HIGH);

  mcp.pinMode(pin71, INPUT);
  mcp.pullUp(pin71, HIGH);

  mcp.pinMode(pin72, INPUT);
  mcp.pullUp(pin72, HIGH);

  pinMode(D3, OUTPUT); //สัญญาณ Connect Wifi

  pinMode(D5, OUTPUT);   //Relay 4 ตัว
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D0, OUTPUT);

  mcp.pinMode(pin81, OUTPUT);   //ไฟสถานะตู้ ON/OFF
  mcp.pinMode(pin82, OUTPUT);
   Wificonnect();

}


void loop() {
 
    if (WiFi.status() == WL_CONNECTED) {
      mcp.digitalWrite(pin81,HIGH);
      mcp.digitalWrite(pin82,LOW);
    digitalWrite(D3, HIGH);
  } 
  if (WiFi.status() != WL_CONNECTED ) {
    mcp.digitalWrite(pin82, HIGH);
    mcp.digitalWrite(pin81,LOW);
    digitalWrite(D3, LOW);
  }
    Zone1();
    Zone2();
    Zone3();
    Zone4();
    Zone5();
    Zone6();
    Zone7();
    Relay1();
    Relay2();
    Relay3();
    Relay4();
  delay(1000);
}
