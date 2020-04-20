void pumt() {
  int d5 = 0, d6 = 0, i;
  for (i = 0; i < 1000; i++) {
    d5 += digitalRead(D5);
    d6 += digitalRead(D6);
//    delay(200);
  }
  Serial.print("d5 = ");
  Serial.println(d5);
  Serial.print("d6 = ");
  Serial.println(d6);
  if (d5 > 970) {
    d5 = 1;
  } else {
    d5 = 0;
  }
  if (d6 > 970) {
    d6 = 1;
  } else {
    d6 = 0;
  }
  if (clk == 1 ) {
    PumON();
    clk = 2;
  }
  Serial.print("CLK = ");
  Serial.println(clk);
  Serial.print("PUM = ");
  Serial.println(d5 + d6);
  if ((d5 + d6) == 2 && clk == 2) {
    
  Serial.print("qqqqqqqqqqqqqqqqqqqqqqq");
    PumOFF();
    clk = 3;
  }
  if (clk == 3) {
    VoilON();
  }
  if (d5 + d6 == 0 && clk == 3) {
    
  Serial.print("wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww");
    VoilOFF();
    clk = 0;
    day = 0;
  }

}
void PumON() {
  mcp.digitalWrite(7, LOW);
}
void PumOFF() {
  mcp.digitalWrite(7, HIGH);
}
void VoilON() {
  mcp.digitalWrite(8, HIGH);
}
void VoilOFF() {
  mcp.digitalWrite(8, LOW);
}

