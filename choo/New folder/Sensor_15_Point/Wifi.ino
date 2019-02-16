
void Wificonnect(){
  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED&&cout<=30) {
    Serial.print(".");
    delay(500);
    cout++;
  }
  if(cout>0){
    cout=0;
  }
 
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    digitalWrite(D3, HIGH);
  } 
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println();
    Serial.print("Do not connected: ");
    digitalWrite(D3, LOW);
  }
  delay(5000);
}
