#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "Computer";
const char* password = "571733022";

String readStrings = ""; // สร้างตัวแปรมาเก็บข้อมูลค่าที่ส่งเข้ามา

int pin1 = 14; //กำหนด GPIO 14 (D5)
int pin2 = 12; //กำหนด GPIO 12 (D6)
int pin3 = 13; //กำหนด GPIO 13 (D7)
int pin4 = 15; //กำหนด GPIO 15 (D8)

WiFiServer server(80); //สร้าง object ของ class WiFiServer ขึ้นมาและส่งค่าพารามิเตอร์ 80 เพื่อกำหนดพอร์ต
WiFiClient client;
void setup() {
  Serial.begin(115200); //กำหนด baudrate ที่ 115200
  delay(10);

  pinMode(pin1, OUTPUT); //เซต pin1 ให้เป็น output
  pinMode(pin2, OUTPUT); //เซต pin2 ให้เป็น output
  pinMode(pin3, OUTPUT); //เซต pin3 ให้เป็น output
  pinMode(pin4, OUTPUT); //เซต pin4 ให้เป็น output

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); //แสดงข้อความ Connecting to (ชื่อ SSID ที่เราตั้ง) ผ่านทาง Serial

  WiFi.begin(ssid, password); // เริ่มเชื่อมต่อไปยัง ssid และ password ที่เรากำหนด

  while (WiFi.status() != WL_CONNECTED) { // ถ้ายังไม่เชื่อมต่อกับ wifi ให้ทำการวน loop ไปเรื่อย ๆ และ print ข้อความ ... ออกมา
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");//เมื่อเชื่อมต่อกับ wifi ได้แล้วให้ แสดง WiFi connected ผ่าน Serial

  // Start the server
  server.begin(); //ให้ทำการเริ่ม server
  Serial.println("Server started"); //แสดงข้อความว่า Server started ผ่าน Serial

  // Print the IP address
  Serial.println(WiFi.localIP()); //แสดง IP Address ทาง Serial

}
int cout=0;
void loop() {
  // put your main code here, to run repeatedly:
  client = server.available(); // สร้าง object ชื่อ client จาก class WiFiClient ให้เท่ากับ Server.available()

  if (client) { //ถ้ามี client เชื่อมต่อ ให้เข้าทำงานในเงื่อนไข
    Serial.println("Yes client"); // แสดง Yes client ทาง Serial

    while (client.connected()) { // ถ้าหาก client กำลังเชื่อมต่อ ให้เข้า loop
      if (client.available()) { // ถ้าเข้าเงื่อนไขนี้แสดงว่ามีข้อมูลผ่านเข้ามา
        char c = client.read(); // สร้างตัวแปร char เพื่อเก็บข้อมูลที่อ่านได้
  

        if (readStrings.length() < 120) { // ถ้าหากตัวแปร readStrings มีขนาดไม่เกิน 100 ก็ให้ตัวแปร readStrings เพิ่มข้อมูลจากค่าที่อ่านได้จาก server
          readStrings += c;
        }

        if (c == '\n') { // เมื่ออ่านข้อมูลเจอ \n ก็ให้ทำเงื่อนไขต่อไป
          Serial.println(readStrings); // แสดงข้อมูลที่อ่านได้ทั้งหมดแสดงผ่าน Serial
          client.print("HTTP/1.1 200 OK\r\n"); //send new page
          client.print("Content-Type: text/html\r\n\r\n");
          client.print("<!DOCTYPE HTML>\r\n");
          client.print("<HTML>\r\n");//html tag
          client.print("<HEAD>\r\n"); //
          //            client.print("<meta http-equiv='refresh' content='10'/>\r\n");
          client.print("<meta name='apple-mobile-web-app-capable' content='yes' />\r\n");
          client.print("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />\r\n");
          client.print("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />\r\n");
          client.print("<TITLE>NodeMCU Project</TITLE>\r\n");
          client.print("</HEAD>\r\n");
          client.print("<BODY>\r\n");//ในส่วนของ body คือสิ่งที่จะแสดงไปยังหน้า web
          client.print("<form action=\"192.168.0.153\">");
          client.print("<center>");
          client.print("<br />"); //สร้างหัวข้อความที่มีขนาด 1
          client.print("<br />");//ขีดเส้นใต้
          client.print("<br />");  //ขึ้นบรรทัดใหม่
          client.print("<br />"); //สร้างหัวข้อความที่มีขนาด 2
          client.print("<br />");  //ขึ้นบรรทัดใหม่
          client.print("<br />");//สร้าง link เมื่อคลิกจะส่งค่าไปที่ server อ่านแล้วเอาไปควบคุม relay
          client.print("<input type=\"time\" name =\"time1\">");
          client.print("<input type=\"checkbox\" name = \"cb1\">");
          client.print("<br />");
          client.print("<br />");
          client.print("<input type=\"time\" name =\"time2\">");
          client.print("<input type=\"checkbox\" name = \"cb2\">");
          client.print("<br />");
          client.print("<br />");
          client.print("<input type=\"time\" name =\"time3\">");
          client.print("<input type=\"checkbox\" name = \"cb3\">");
          client.print("<br />");
          client.print("<br />");
          client.print("<br />");
          client.print("<input type = \"submit\" name =\"bt1\" value = \"Send\">");
          client.print("</center>");
          client.print("</form>");
          client.print("</BODY>\r\n");
          client.print("</HTML>\n");// ปิด tag

          delay(1);

          client.stop(); // เมื่อส่งไปแล้วก็ให้ client stop เพื่อหยุดการทำงาน

//          Serial.println(server.arg("time1"));
          //ส่วนที่เหลือก็จะเป็นเช็คข้อความที่อ่านได้เพื่อไปควบคุม relay แต่ละ channel
          Serial.print("sss = ");
      Serial.println(readStrings[26]);
      readStrings = ""; 
       
         // readStrings = ""; //เมื่อจบโปรแกรมก็ให้ตัวแปร readStrings เคลียค่าทั้งหมด เพื่อรอรับค่าใหม่
        }//if(c == '\n')
      }//if(client.available())
     
    }//while(client.connected())
  }//if(client)
}//void loop()
