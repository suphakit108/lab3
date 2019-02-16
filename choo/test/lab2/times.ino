void printDateTime(const RtcDateTime& dt)
{
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u:%02u:%02u"),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.println(datestring);
}
int h=3,m=15 ,s=0;
int Chlktime(const RtcDateTime& dt){
  if(h== dt.Hour()&&m== dt.Minute()&&(s==dt.Second()||s+1==dt.Second()||s+2==dt.Second())){
    eat=1;
    OldKg=get_units_kg();
    MoterNO();
    delay(2000);
   }
}

