int coutZone11=0;
int coutZone12=0;
int coutZone13=0;
int coutZone21=0;
int coutZone22=0;
int coutZone23=0;
int coutZone31=0;
int coutZone32=0;
int coutZone41=0;
int coutZone42=0;
int coutZone51=0;
int coutZone61=0;
int coutZone71=0;
int coutZone72=0;
void Zone1() {
  if(mcp.digitalRead(pin11) == 0) {
    coutZone11++;
  }
  if (mcp.digitalRead(pin11) != 0){
    coutZone11=0;
   }
  if(coutZone11==3){
     delay(10);
    String message = "Zone1 ระดับ1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone11=0;
  }
  if(mcp.digitalRead(pin12) == 0) {
     coutZone12++;
  }
  if(coutZone12==3){
    delay(10);
    String message = "Zone1 ระดับ2"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("2");
    CallLine(message);
    Cutoutdoor[0]=1;
    coutZone12=0;
  }
   if (mcp.digitalRead(pin12) != 0){
    Serial.println(Cutoutdoor[0]);
    Cutoutdoor[0]=0;
    coutZone12=0;
   }
  if (mcp.digitalRead(pin13) == 0) {
    coutZone13++;
  }
  if(coutZone13==3){
    delay(10);
    String message = "Zone1 ระดับ3"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("3");
    CallLine(message);
    Cutindoor[0]=1;
    coutZone13=0;
  }
  if (mcp.digitalRead(pin13) != 0) {
    Cutindoor[0]=0;
    coutZone13=0;
  }
  Serial.println("END ZONE1");
}
//-----------------------------------------------------------------------------------------------------------------

void Zone2() {
  if(mcp.digitalRead(pin21) == 0) {
    coutZone21++;
  }
  if (mcp.digitalRead(pin21) != 0) {
    coutZone21=0;
  }
  if(coutZone21==3){
    delay(10);
    String message = "Zone2 ระดับ1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone21=0;
  }
  if(mcp.digitalRead(pin22) == 0) {
     coutZone22++;
  }
  if(coutZone22==3){
    delay(10);
    String message = "Zone2 ระดับ2"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("2");
    CallLine(message);
    Cutoutdoor[1]=1;
    coutZone22=0;
  }
   if (mcp.digitalRead(pin22) != 0){
    Cutoutdoor[1]=0;
    coutZone22=0;
   }
  if (mcp.digitalRead(pin23) == 0) {
    coutZone23++;
  }
  if(coutZone23==3){
    delay(10);
    String message = "Zone2 ระดับ2"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("2");
    CallLine(message);
    Cutindoor[1]=1;
    coutZone23=0;
  }
  if (mcp.digitalRead(pin23) != 0) {
    Cutindoor[1]=0;
    coutZone23=0;
  }
  Serial.println("END ZONE2");
}

//---------------------------------------------------------------------------------------------------------------

void Zone3() {
  if(mcp.digitalRead(pin31) == 0) {
    coutZone31++;
  }
  if (mcp.digitalRead(pin31) != 0){
    coutZone31=0;
  }
  if(coutZone31==3){
    delay(10);
    String message = "Zone3 ระดับ1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone31=0;
  }
  if(mcp.digitalRead(pin32) == 0) {
     coutZone32++;
  }
  if(coutZone32==3){
    delay(10);
    String message = "Zone3 ระดับ2"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("2");
    CallLine(message);
    Cutoutdoor[2]=1;
    coutZone32=0;
  }
   if (mcp.digitalRead(pin32) != 0){
    Cutoutdoor[2]=0;
    coutZone32=0;
   }
  Serial.println("END ZONE3");
}

//-------------------------------------------------------------------------------------------------------------------

void Zone4() {
  if(mcp.digitalRead(pin41) == 0) {
    coutZone41++;
  }
  if (mcp.digitalRead(pin42) != 0){
    coutZone41=0;
   }
  if(coutZone41==3){
    delay(10);
    String message = "Zone4 ระดับ1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone41=0;
  }
  if(mcp.digitalRead(pin42) == 0) {
     coutZone42++;
  }
  if(coutZone42==3){
    delay(10);
    String message = "Zone4 ระดับ2"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("2");
    CallLine(message);
    Cutoutdoor[3]=1;
    coutZone42=0;
  }
   if (mcp.digitalRead(pin42) != 0){
    Cutoutdoor[2]=0;
    coutZone42=0;
   }
  Serial.println("END ZONE4");
}

//----------------------------------------------------------------------------------------------------------------------

void Zone5() {
   Serial.println(coutZone51);
  if(mcp.digitalRead(pin51) == 0) {
    coutZone51++;
  }
  if(mcp.digitalRead(pin51) != 0){
    coutZone51=0;
  }
  if(coutZone51==3){
    delay(10);
    String message = "Zone5 น้ำล้น"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone51=0;
  }
  Serial.println("END ZONE5");
}

//-----------------------------------------------------------------------------------------------------------------

void Zone6() {
   Serial.println(coutZone61);
  if(mcp.digitalRead(pin61) == 0) {
    coutZone61++;
  }
  if (mcp.digitalRead(pin61) != 0){
    coutZone61=0;
  }
  if(coutZone61==3){
    delay(10);
    String message = "Zone6 ระดับ1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย
    Serial.println("1");
    CallLine(message);
    coutZone61=0;
  }
  Serial.println("END ZONE6");
}

//---------------------------------------------------------------------------------------------------------------

void Zone7() {
  
   Serial.println(coutZone71);
   
   Serial.println(coutZone72);
  if(mcp.digitalRead(pin71) == 0) {
    coutZone71++;
  }
  if (mcp.digitalRead(pin71) != 0){
    coutZone71=0;
    TanKWater[0]=0;
  }
  if(coutZone71==3){
   delay(10);
    String message = "Zone7";
    CallLine(message); 
     message = "น้ำเต็ม";
    Serial.println("1");
    CallLine(message);
    TanKWater[0]=1;
    coutZone71=0;
  }
  
  if(mcp.digitalRead(pin72) == 0) {
    coutZone72++;
  }
  if (mcp.digitalRead(pin72) != 0){
    coutZone72=0;
    TanKWater[1]=0;
  }
  if(coutZone72==3){
   delay(10);
    String message = "Zone7";
    CallLine(message); 
     message = "ตรวจสอบแท้งน้ำ";
    Serial.println("2");
    CallLine(message);
    coutZone72=0;
    TanKWater[1]=1;
  }

  Serial.println("END ZONE7");
}
