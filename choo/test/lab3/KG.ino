void kg() {
//  Serial.print("Reading: ");
  Kgall = get_units_kg();
  String data = String((Kgall), DEC_POINT);
//  Serial.print(data);
//  Serial.println(" kg");
  RawValue = analogRead(analogIn);
//  Serial.println(RawValue);
}

float get_units_kg()
{
  float num = -81.49;
  return ((scale.get_units() * 0.453592) + offset + num);
}
