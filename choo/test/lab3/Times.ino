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
int Time1[4],Time2[4],Time3[4],CTime=0;
int h=17,m=2 ,s=0;
void STETime(){
  if(CTime == 0 && Time1[3] == 1 ){
    h = Time1[0];
    m = Time1[1];
    Kg  = Time1[2];
    CTime = 1;
  }
  if(CTime == 1 && Time2[3] == 1){
    h = Time2[0];
    m = Time2[1];
    Kg  = Time2[2];
    CTime = 2;
  }
  if(CTime == 2 && Time3[3] == 1){
    h=Time3[0];
    m=Time3[1];
    Kg  = Time3[2];
    CTime = 0;
  }    
}
int Chlktime(const RtcDateTime& dt){
  if(h== dt.Hour()&&m== dt.Minute()&&(s==dt.Second()||s+1==dt.Second()||s+2==dt.Second())){
    eat=1;
    OldKg=get_units_kg();
    MoterNO();
    delay(2000);
   }
}

