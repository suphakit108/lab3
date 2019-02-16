void Pumon(){
  mcp.digitalWrite(7,LOW);
   lcd.clear();
   lcd.print("pum ON");  
}
void Pumoff(){
  mcp.digitalWrite(7,HIGH); 
   lcd.clear();
   lcd.print("pum OFF");  
}
void soon(){
  mcp.digitalWrite(9,HIGH);
   lcd.clear();
   lcd.print("SO ON");
}
void sooff(){
 mcp.digitalWrite(9,LOW);
 
   lcd.clear();
   lcd.print("SO OFF");
}

