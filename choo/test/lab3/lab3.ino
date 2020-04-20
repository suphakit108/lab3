#include "HX711.h"
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <RtcDS1307.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <FS.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ArduinoJson.h>
LiquidCrystal_I2C lcd(0x3F, D1, D2);
//=====================================
const char* ssid = "Computer";
const char* password = "571733022";     // Config MQTT Server
char mqtt_server[40] = "m11.cloudmqtt.com";
char espport[6] ;
int mqtt_port = 19443;
char host[40];
char device_name[34];
int port;
#define mqtt_user "test"
#define mqtt_password "12345"
WiFiClient espClient;
PubSubClient client(espClient);
//=====================================
float calibration_factor = 46655.00;
#define zero_factor 169247
#define DOUT  D7
#define CLK   D8
#define DEC_POINT  2
float offset = 0;                           //น้ำหนัก
//float get_units_kg();
HX711 scale(DOUT, CLK);
//=====================================
const int analogIn = A0; //วัดกระเเส
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
#define ONE_WIRE_BUS D3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//=====================================
int clk = 0, day = 0;
int deful = 0;
int Time1[4], Time2[4], Time3[4], Timep[3] , CTime = 0;
int h = 17, m = 2 , s = 0, h1, m1;
float Kgall, tt;
int level;
//======================================
byte customChar8[8] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
//flag for saving data
bool shouldSaveConfig = false;

//callback notifying us of the need to save config
void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

void setup()
{ Rtc.Begin();
  lcd.begin();
  mcp.begin();      // Default device address 0
  mcp.pinMode(MCP_LEDTOG1, OUTPUT);  // Toggle LED 1
  mcp.pinMode(MCP_LEDTOG2, OUTPUT);  // Toggle LED 2
  mcp.pinMode(10, INPUT);
  mcp.pullUp(10, HIGH);
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(8, OUTPUT);
  Serial.begin(115200);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  PumOFF();
  MoterOFF();
  WiFi.mode(WIFI_STA);
  scale.set_scale(calibration_factor);
  scale.set_offset(zero_factor);

  sensors.begin();
  pinMode(analogIn, INPUT);

  Serial.println("Load Cell");
  ConnectWifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  //     lcd.init();
  lcd.backlight();
  lcd.createChar(0, customChar8);
}
float  Kg = 2, OldKg;
int eat = 0;
void loop () {
  deful = 0 ;
  if (mcp.digitalRead(10)) {
    lcd.clear();
    lcd.print("192.168.4.1");
    wifi_manager_loop();
  }
  else {
    level = digitalRead(D5) + digitalRead(D6);
    if (WiFi.status() == WL_CONNECTED) {
      lcd.clear();

    }
    if (WiFi.status() != WL_CONNECTED) {
      lcd.clear();

    }
    mqtt();
    client.loop();
    RtcDateTime now = Rtc.GetDateTime();
    printDateTime(now);
    Chlktime(now);
    sensors.requestTemperatures();
    tt = sensors.getTempCByIndex(0);
    sensors.getTempFByIndex(0);

    if (clk == 0) {
      int i = 0;
      kg();
      Serial.print("deful =");
      Serial.println(deful);
      Serial.print(h);
      Serial.println(" : ");
      Serial.println(m);
      Serial.println("CTime = ");
      Serial.println(CTime);
      Serial.print("Time1 = ");
      Serial.print(Time1[0]);
      Serial.print(" : ");
      Serial.print(Time1[1]);
      Serial.print(" = ");
      Serial.println(Time1[3]);
      Serial.print("Time2 = ");
      Serial.print(Time2[0]);
      Serial.print(" : ");
      Serial.print(Time2[1]);
      Serial.print(" = ");
      Serial.println(Time2[3]);
      Serial.print("Time3 = ");
      Serial.print(Time3[0]);
      Serial.print(" : ");
      Serial.print(Time3[1]);
      Serial.print(" = ");
      Serial.println(Time3[3]);
      if (eat == 1) {
        for (i = 0; i < 500; i++) {
         if(eat == 0){
          i=500;
         }
          lcd.clear();
          lcd.print("eat = ");
          lcd.print(eat);
          Eat();
          Serial.println(eat);
          delay(200);
        }
      }
      if (eat != 1) {
        MoterOFF();
        MoterOFF();
        delay(1000);

      }
      if (deful != 0) {
        STETime();
      }

    }

    if (clk > 0) {
      kg();
      pumt();
    }

  }
}
int Eat() {
  kg();
  float sss = OldKg - Kgall;
  Serial.print(OldKg);
  Serial.print(" - ");
  Serial.print(Kgall);
  Serial.print(" = ");
  Serial.println(sss);
  Serial.println(Kg);

  if (Kgall >= 0) {
    if (sss > Kg) {
      MoterOFF();
      MoterOFF();
      Serial.println("done");
      CTime++;
      deful = 1;
      eat = 0;
      Serial.println("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
      //      return 0;
    }
    //    else {
    //      return 1;
    //    }
    if (CTime == 3) {
      CTime = 0;
    }
    //    if (analogRead(analogIn) < 740) {
    //      MoterOFF();
    //      delay(1000);
    //      MoterRE();
    //      delay(1000);
    //      MoterNO();
    //      delay(1000);
    //      MoterOFF();
    //      MoterNO();
    //
    //    }
  }
}

