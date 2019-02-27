#include "HX711.h"
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <RtcDS1307.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>
LiquidCrystal_I2C lcd(0x3F, D1, D2);
//=====================================
const char* ssid = "Computer";
const char* password = "571733022";     // Config MQTT Server
#define mqtt_server "m11.cloudmqtt.com"
#define mqtt_port 19443
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
int clk = 0,day=0;
int deful = 0;
int Time1[4], Time2[4], Time3[4],Timep[3] ,CTime = 0;
int h = 17, m = 2 , s = 0,h1,m1;
float Kgall,tt;
int level;
void setup()
{
  WiFi.mode(WIFI_STA);
  scale.set_scale(calibration_factor);
  scale.set_offset(zero_factor);
  Rtc.Begin();
  lcd.begin();
  mcp.begin();      // Default device address 0
  mcp.pinMode(MCP_LEDTOG1, OUTPUT);  // Toggle LED 1
  mcp.pinMode(MCP_LEDTOG2, OUTPUT);  // Toggle LED 2
  mcp.pinMode(10, INPUT);
  mcp.pullUp(10, HIGH);
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(8, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
  pinMode(analogIn, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  Serial.println("Load Cell");
  ConnectWifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  PumOFF();
  MoterOFF();
}
float eat = 0, Kg = 2, OldKg;
void loop () {
   level = digitalRead(D5) + digitalRead(D6);
  if (WiFi.status() == WL_CONNECTED) {
    lcd.clear();
    lcd.print("WiFi Connected");
  }
  if (WiFi.status() != WL_CONNECTED) {
    lcd.clear();
    lcd.print("WiFi Notconnect");
  }
  mqtt();
  client.loop();
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Chlktime(now);
  sensors.requestTemperatures();
  tt=sensors.getTempCByIndex(0);
  sensors.getTempFByIndex(0);
  Serial.println(tt);
  if (clk == 0) {
    kg();
    Serial.print("eat = ");
    Serial.println(eat);
    Serial.print("OldKg = ");
    Serial.println(OldKg);
    Serial.print(Kgall);
    Serial.print(" = ");
    Serial.println(Kg);
    Serial.print("deful =");
    Serial.println(deful);
    if (eat == 1) {
      Eat();
    }
    if (deful != 0) {
      STETime();
    }
  }

  if (clk > 0) {
    pumt();
  }

  delay(1000);
}
void Eat() {
  Serial.println("eat");
  if (OldKg - Kgall > Kg) {
    MoterOFF();
    MoterOFF();
    eat = 0;
    Serial.println("done");
    CTime++;
  }
  if (CTime == 3) {
    CTime = 0;
  }
  if (analogRead(analogIn) < 740) {
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

