void mqtt() {
  if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
     lcd.clear();
     lcd.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("/Time");
      client.subscribe("/come");
      client.subscribe("/pum");
      client.subscribe("/set");
      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      return;
    }
  }
}

