#include "HX711.h"
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <RtcDS1307.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
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
float calibration_factor = 47247.00;
#define zero_factor 88818
#define DOUT  D7
#define CLK   D8
#define DEC_POINT  2
float offset = 0;                           //น้ำหนัก
float get_units_kg();
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
int clk = 0;
int deful = 0;
void setup()
{
  WiFi.mode(WIFI_STA);
  scale.set_scale(calibration_factor);
  scale.set_offset(zero_factor);
  Rtc.Begin();
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
  Serial.println("Load Cell");
  ConnectWifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

}
float eat = 0, Kg = 2, OldKg;
void loop () {
  mqtt();
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
  Chlktime(now);
  if (clk == 0) {
    kg();
    Serial.print("eat = ");
    Serial.println(eat);
    Serial.print("OldKg = ");
    Serial.println(OldKg);
    Serial.print(OldKg - get_units_kg());
    Serial.print(" = ");
    Serial.println(Kg);
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
  client.loop();
  delay(1000);

}
void Eat() {
  Serial.println("กิน");
  if (OldKg - get_units_kg() > Kg) {
    MoterOFF();
    eat = 0;
    Serial.println("อิ่ม");
  }
  if (analogRead(analogIn) < 800) {
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

