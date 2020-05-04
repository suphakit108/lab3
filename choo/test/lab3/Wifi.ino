

void ConnectWifi() {
  Serial.println();
  Serial.print("Connecting to ");
  lcd.print("Connecting Wifi ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    lcd.print(".");
  }                                       //*WiFi
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  msg = "";
  tp = "";
  tp = topic;
 int i;
  while (i < length) msg += (char)payload[i++];
  Serial.println(msg);
  if (tp == "/Time" || tp == "/pum") {
  spiffs_Write(msg);
   PlassInt();
  }
  GetTime();
  deful = 1;
  delay(500);
  Serial.println(msg);
  if (msg != "get" && msg != "success" && (tp == "/Time" || tp == "/pum")) {
    client.publish("/set", "success");

  }
}
int PlassInt(){
  int i;
    for (i = 0; i < msg.length(); i++) {
      Serial.println(msg[i]);
      if (msg[i] == '0') {
        st[i] = 0;
      }
      if (msg[i] == '1') {
        st[i] = 1;
      }
      if (msg[i] == '2') {
        st[i] = 2;
      }
      if (msg[i] == '3') {
        st[i] = 3;
      }
      if (msg[i] == '4') {
        st[i] = 4;
      }
      if (msg[i] == '5') {
        st[i] = 5;
      }
      if (msg[i] == '6') {
        st[i] = 6;
      }
      if (msg[i] == '7') {
        st[i] = 7;
      }
      if (msg[i] == '8') {
        st[i] = 8;
      }
      if (msg[i] == '9') {
        st[i] = 9;
      }
    }
}
void GetTime() {
  int i;

  Serial.println();
  Serial.println("asdasda");
  if (tp == "/Time") {
    
    Time1[0] = st[0] * 10 + st[1];
    Time1[1] = st[2] * 10 + st[3];
    Time1[2] = st[4] * 1000 + st[5] * 100 + st[6]*10 + st[7] ;
    Time1[3] = st[8];

    Time2[0] = st[9] * 10 + st[10];
    Time2[1] = st[11] * 10 + st[12];
    Time2[2] = st[13] * 1000 + st[14] * 100 + st[15]*10 + st[16];
    Time2[3] = st[17];

    Time3[0] = st[18] * 10 + st[19];
    Time3[1] = st[20] * 10 + st[21];
    Time3[2] = st[22] * 1000 + st[23] * 100 + st[24]*10 + st[25];
    Time3[3] = st[26];
    deful = 0;
  }
  if (tp == "/pum") {

    clk = 1;
    deful = 0;
  }
  char strr[9];
  String Nums;
  if (Time1[3] == 1 && tp == "/come" && msg == "Setting") {
    Nums = "1" + String(Time1[0] / 10) + String(Time1[0] % 10) + String(Time1[1] / 10) + String(Time1[1] % 10) + String(Time1[2] / 1000) + String((Time1[2] % 1000) / 100) + String((Time1[2] % 100) / 10) + String(Time1[2] % 10);
    for (i = 0 ; i <= 9; i++) {
      strr[i] = Nums[i];
    }
    client.publish("/set", strr);
  }
  if (Time2[3] == 1 && tp == "/come" && msg == "Setting") {
    Nums = "2" + String(Time2[0] / 10) + String(Time2[0] % 10) + String(Time2[1] / 10) + String(Time2[1] % 10) + String(Time2[2] / 1000) + String((Time2[2] % 1000) / 100) + String((Time2[2] % 100) / 10) + String(Time2[2] % 10);
    for (i = 0 ; i <= 9; i++) {
      strr[i] = Nums[i];
    } client.publish("/set", strr);
  }
  if (Time3[3] == 1 && tp == "/come" && msg == "Setting") {
    Nums = "3" + String(Time3[0] / 10) + String(Time3[0] % 10) + String(Time3[1] / 10) + String(Time3[1] % 10) + String(Time3[2] / 1000) + String((Time3[2] % 1000) / 100) + String((Time3[2] % 100) / 10) + String(Time3[2] % 10);
    for (i = 0 ; i <= 9; i++) {
      strr[i] = Nums[i];
    }
    client.publish("/set", strr);
  }
  if (tp == "/come" && msg == "get") {
    int i = 0, c = 0;
    char strr[8];
    String xxx = String(int(Kgall * 100));
    xxx = xxx + String(int(tt * 100));
    xxx = xxx + String(level);
    if (int(Kgall * 100) < 100) {
      strr[i] = '0';
      i++;
      c++;
    }
    if (int(Kgall * 100) < 10) {
      strr[i] = '0';
      i++;
      c++;
    }
    for ( ; i < 8; i++) {
      strr[i] = xxx[i - c];
    }
    Serial.println( level);
    client.publish("/come", strr);

  }
}

