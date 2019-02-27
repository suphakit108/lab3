
String msg = "";
String tp = "";
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
  int st[24], i;
  while (i < length) msg += (char)payload[i++];
  if (tp == "/Time") {
    for (i = 0; i < msg.length(); i++) {
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
    for (i = 0; i < msg.length(); i++) {
      Serial.print(st[i]);
    }
    Serial.println();
  }
  GetTime(st);
  deful = 1;
  delay(500);
  Serial.println(msg);
}

void GetTime(int st[]) {
  int i;
  for ( i = 0; i < 24; i++) {
    Serial.print(st[i]);
  }
  Serial.println();
  Serial.println("asdasda");
  if (tp == "/Time") {
    Time1[0] = st[0] * 10 + st[1];
    Time1[1] = st[2] * 10 + st[3];
    Time1[2] = st[4] * 100 + st[5] * 10 + st[6];
    Time1[3] = st[7];

    Time2[0] = st[8] * 10 + st[9];
    Time2[1] = st[10] * 10 + st[11];
    Time2[2] = st[12] * 100 + st[13] * 10 + st[14];
    Time2[3] = st[15];

    Time3[0] = st[16] * 10 + st[17];
    Time3[1] = st[18] * 10 + st[19];
    Time3[2] = st[20] * 100 + st[21] * 10 + st[22];
    Time3[3] = st[23];
    deful = 1;
  }
  if (tp == "/pum") {
    Timep[0] = st[0] * 10 + st[1];
    Timep[1] = st[2] * 10 + st[3];
    Timep[2] = st[5];
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

