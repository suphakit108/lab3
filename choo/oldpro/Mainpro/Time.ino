int TimeC=2,T=0;
void Time(){
  RtcDateTime currentTime = rtcObject.GetDateTime();    //get the time from the RTC
  char str[20];   //declare a string as an array of chars
  sprintf(str, "%d/%d/%d %d:%d:%d",     //%d allows to print an integer to the string
          currentTime.Year(),   //get year method
          currentTime.Month(),  //get month method
          currentTime.Day(),    //get day method
          currentTime.Hour(),   //get hour method
          currentTime.Minute(), //get minute method
          currentTime.Second()  //get second method
         );      
  Serial.println(str); //print the string to the serial port
  // delay(1000);
  
   if(b+1==currentTime.Minute()){
   Set=0; 
   }
  if(Set<3){
  if( currentTime.Hour()== a && currentTime.Minute()== b ){
    Moter();
    }
   ///////////////////////////////////////////////////////
  if(TimeC>T){
    a=a+((24-a)/2);
   }
  if(currentTime.Hour()== 0 && currentTime.Minute()== 1){
    T = 0; 
  }
  ///////////////////////////////////////////////////////
  }
//  else if(currentTime.Minute()%10==0){
//    dht22();
//    ds18();
//   }
  }


