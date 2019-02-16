int KGs=2;
float kg1;
void Moteron(){
  Set=1;
  mcp.digitalWrite(x,720);
  mcp.digitalWrite(y,0);
  }
void Moteroff(){
  mcp.digitalWrite(x,0);
  mcp.digitalWrite(y,0);
  KGs=0;
  }
float data ;
int in ;
void clk(){
    if(KGs==2){
    Serial.println("TEsT 5 s");
    Moteron();
    delay(5000);
    Moteroff();
    KGs=0;
    Set=0;
    }
  data = String((get_units_kg()+offset), DEC_POINT).toFloat();
  in = analogRead(A0);
  if(in<800){
    mcp.digitalWrite(x,0);
    mcp.digitalWrite(y,1023);
    delay(500);
    mcp.digitalWrite(y,0);
    Moteron();
    }
  if(KGs==1){
    if(Kg/100<=kg1-data){
      Moteroff();
      KGs=0;
      
      }
    }
  Serial.print(data);
  Serial.println(" kg");
  Serial.println(in);
  Serial.print("timeset = ");
  Serial.print(a);
  Serial.print(".");
  Serial.println(b);
  Serial.print("Kgs = ");
  Serial.println(KGs);
  Serial.print("Kg = ");
  Serial.println(Kg/100);
  Serial.print("kg1-data = ");
  Serial.println(kg1-data);
   //delay(1000);
   }
void Moter(){
  Serial.print("Reading: ");
  float data = String((get_units_kg()+offset), DEC_POINT).toFloat();
  if(KGs==0&&Set==0){
    Moteron();
    kg1=data;
    KGs=1;
    }
    
  }
float get_units_kg(){
  return(scale.get_units()*0.453592);
  }

