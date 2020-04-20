void printDateTime(const RtcDateTime& dt)
{
  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u:%02u:%02u"),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
             lcd.setCursor(0, 0);
             lcd.print(datestring);
             lcd.setCursor(0, 1);
             lcd.print(Kgall);
             lcd.print(" kg");
             lcd.print(" ");
             lcd.print(tt);
               lcd.write(0);
             lcd.print("C");
  Serial.println(datestring);
}
void STETime() {

  if (CTime == 0 && Time1[3] == 1 ) {
    h = Time1[0];
    m = Time1[1];
    Kg  = float(Time1[2]) / 1000;
  }
  if (CTime == 1 && Time2[3] == 1) {
    h = Time2[0];
    m = Time2[1];
    Kg  = float(Time2[2]) / 1000;
  }
  if (CTime == 2 && Time3[3] == 1) {
    h = Time3[0];
    m = Time3[1];
    Kg  = float(Time3[2]) / 1000;
  }
  deful=0;
}
int Chlktime(const RtcDateTime& dt) {
  Serial.println(" H = ");
  Serial.println(h);
  Serial.println(" m = ");
  Serial.println(m);
  if (h == dt.Hour() && m == dt.Minute() && (s == dt.Second() || s + 1 == dt.Second() || s + 2 == dt.Second())) {
    eat = 1;
    OldKg = Kgall;
    MoterNO();
//    delay(2000);
  }
  if (Timep[0] == dt.Hour() && Timep[1] == dt.Minute() && (s == dt.Second() || s + 1 == dt.Second() || s + 2 == dt.Second())) {
    clk = 1;
    day = 3;
//    delay(2000);
  }
  if (0 == dt.Hour() && 0 == dt.Minute() && (s == dt.Second() || s + 1 == dt.Second() || s + 2 == dt.Second())) {
    day++;
//    delay(2000);
  }
}

