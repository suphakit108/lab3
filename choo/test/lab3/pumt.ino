void pumt() {
  if (clk == 1) {
    PumON();
    clk = 2;
  }
  Serial.println(digitalRead(D5) + digitalRead(D6));
  if (digitalRead(D5) + digitalRead(D6) == 2 && clk == 2) {
    PumOFF();
    clk = 3;
  }
  if (clk == 3) {
    VoilON();
  }
  if (digitalRead(D5) + digitalRead(D6) == 0 && clk == 3) {
    VoilOFF();
    clk = 0;
  }

}
void PumON() {
  mcp.digitalWrite(7, LOW);
  Serial.print("Casdasdasd ");
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

