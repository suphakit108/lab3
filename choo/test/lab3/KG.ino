void kg(){
  Serial.print("Reading: ");
  String data = String((get_units_kg()), DEC_POINT);
  Serial.print(data);
  Serial.println(" kg");
  RawValue = analogRead(analogIn);
  Serial.println(RawValue);
}
float get_units_kg()
{
  float num = -0.38;
  return((scale.get_units()*0.453592)+offset+num);
}
