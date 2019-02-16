void Relay1(){
      Serial.println(Cutoutdoor[0]+Cutoutdoor[1]+Cutoutdoor[2]+Cutoutdoor[3]);
  if((Cutoutdoor[0]+Cutoutdoor[1]+Cutoutdoor[2]+Cutoutdoor[3])>0){
    Serial.println("1ตัด");
    digitalWrite(D5, LOW);
  }
  if((Cutoutdoor[0]+Cutoutdoor[1]+Cutoutdoor[2]+Cutoutdoor[3])==0){
    Serial.println("1ไม่ตัด");
    digitalWrite(D5, HIGH);
  }
}

void Relay2(){
  if((Cutindoor[0]+Cutindoor[1])>0){
    Serial.println("2ตัด");
    digitalWrite(D6, LOW);
  }
  if((Cutindoor[0]+Cutindoor[1])==0){
    Serial.println("2ไม่ตัด");
    digitalWrite(D6, HIGH);
  }
}

void Relay3(){
  if((Cutoutdoor[0]+Cutoutdoor[1]+Cutoutdoor[2]+Cutoutdoor[3]+Cutindoor[0]+Cutindoor[1])>0){
    Serial.println("3ต่อ");
    digitalWrite(D7, HIGH);
  }
  if((Cutoutdoor[0]+Cutoutdoor[1]+Cutoutdoor[2]+Cutoutdoor[3]+Cutindoor[0]+Cutindoor[1])==0){
    Serial.println("3ไม่ต่อ");
    digitalWrite(D7, LOW);
  }
}
void Relay4(){
  if((TanKWater[0]+TanKWater[1]) > 0){
    Serial.println("4ตัด");
    digitalWrite(D0, LOW);
  }
    if((TanKWater[0]+TanKWater[1])==0){
    Serial.println("4ไม่ตัด");
    digitalWrite(D0, HIGH);
  }
}
