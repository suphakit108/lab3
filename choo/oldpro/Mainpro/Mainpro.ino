#include <ESP8266WiFi.h>
#include <PubSubClient.h>
//#include <OneWire.h>
//#include <DallasTemperature.h>
#include <Wire.h>
#include <RtcDS3231.h>  //RTC library
#include "Adafruit_MCP23017.h"
#include "HX711.h"
#define ONE_WIRE_BUS D3
const char* ssid = "Computer";
const char* password = "571733022";
// Config MQTT Server
#define mqtt_server "m11.cloudmqtt.com"
#define mqtt_port 19443
#define mqtt_user "test"
#define mqtt_password "12345"
///////////////////////////////////////////////
float calibration_factor =47466.00; 
#define zero_factor 27892
#define DOUT  D7                          
#define CLK   D8                          //*loadcell
#define DEC_POINT  2
float offset=0;
float get_units_kg();
HX711 scale(DOUT, CLK);
//////////////////////////////////////////
RtcDS3231<TwoWire> rtcObject(Wire); 
Adafruit_MCP23017 mcp;
WiFiClient espClient;
PubSubClient client(espClient);
int x = 1;
int y = 0;
int aa[7],a,b;

//#include "DHT.h"
#define DHTPIN D4 // what digital pin we're connected to
#define DHTTYPE DHT11 // DHT 11
#define ONE_WIRE_BUS D3
//
//
unsigned long interval=6000; // the time we need to wait
unsigned long previousMillis=0; // millis() returns an unsigned long.
//
unsigned long interval2=6000; // the time we need to wait
unsigned long previousMillis2=0; // millis() returns an unsigned long.
//
//DHT dht(DHTPIN, DHTTYPE);
//
//OneWire oneWire(ONE_WIRE_BUS);
//DallasTemperature sensors(&oneWire);
float Celsius = 0;

void setup() {
  
  Serial.print("Connecting to ");
// sensors.begin();
Serial.println("DHTxx set!");
//  dht.begin();
//////////////////////////////////////////  
  mcp.begin();      // use default address 0
  mcp.pinMode(x, OUTPUT);
  mcp.pinMode(y, OUTPUT);
  pinMode(A0,INPUT);                             //*inMCP
  Serial.begin(115200);
  rtcObject.Begin();     //Starts I2C
  delay(10);
//////////////////////////////////////////

//////////////////////////////////////////
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }                                       //*WiFi
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);  
//////////////////////////////////////////
  scale.set_scale(calibration_factor); 
  scale.set_offset(zero_factor);        //*loadcell
//////////////////////////////////////////

}
int Set=0;
void loop() {
  if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("/Time");
      } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      return;
      }
    }
  client.loop();
  unsigned long currentMillis = millis();
  if(analogRead(A0) > 10){
    //if ((unsigned long)(currentMillis - previousMillis) >= interval) 
    {
      clk();
    }
    //if ((unsigned long)(currentMillis - previousMillis2) >= interval) 
    {
      Time();
    }
    delay(1000);
    
}
}
float Kg;
String msg = "";
String tp = "";
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  msg = "";
  tp = "";
  tp=topic;
  int i=0;
  while (i<length) msg += (char)payload[i++];
  if(tp=="/Time"){
    int i=0;
    for (i=0;i<msg.length();i++){
      if(msg[i]=='0'){
        aa[i]=0;
      }
      if(msg[i]=='1'){
        aa[i]=1;
      }
      if(msg[i]=='2'){
        aa[i]=2;
      }
      if(msg[i]=='3'){
        aa[i]=3;
      }
      if(msg[i]=='4'){
        aa[i]=4;
      }
      if(msg[i]=='5'){
        aa[i]=5;
      }
      if(msg[i]=='6'){
        aa[i]=6;
      }
      if(msg[i]=='7'){
        aa[i]=7;
      }
      if(msg[i]=='8'){
        aa[i]=8;
      }
      if(msg[i]=='9'){
        aa[i]=9;
      }
     }
    a=(aa[0]*10)+aa[1];
    b=(aa[2]*10)+aa[3];
    Kg=(aa[4]*100)+(aa[5]*10)+aa[6];
    Kg=Kg/2;
    }
    delay(500);
  Serial.print(msg);
  }
