void spiffs_Write(String number) {
  Serial.print("number");
  Serial.println(number);
  if (success) {
    Serial.println("File system mounted with success");
  } else {
    Serial.println("Error mounting the file system");
    return;
  }

  File file = SPIFFS.open("/file.txt", "w");

  if (!file) {
    Serial.println("Error opening file for writing");
    return;
  }

  int bytesWritten = file.print(String(number));

  if (bytesWritten > 0) {
    Serial.println("File was written");
    Serial.println(bytesWritten);

  } else {
    Serial.println("File write failed");
  }

  file.close();
}

String spiffs_Read() {
  File file2 = SPIFFS.open("/file.txt", "r");
  String num = "00000";
  if (!file2) {
    Serial.println("Failed to open file for reading");
    return num;
  }

  Serial.println("File Content:");
  num = "";
  while (file2.available()) {
    String tmp;

    tmp = char(file2.read());
    num += tmp;
    //    Serial.write(file2.read());
  }
  Serial.println(num);
  return num;
  file2.close();
}
