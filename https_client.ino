#include<Arduino.h>
#include<WiFi.h>
#include <HTTPClient.h>
HTTPClient http;
void setup() {
  Serial.begin(115200);
  WiFi.begin("uday", "9949045424");
 while(WiFi.status()!=WL_CONNECTED)
 {
  Serial.print(".");
 }
 Serial.println(" ");
 Serial.println("WiFi connected success ");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Http begin..\n");
    http.begin("https://developer.mozilla.org/en-US/docs/Web/Reference");
    Serial.println("http get..");
    int code = http.GET();
    if (code > 0)
    {
      Serial.printf("http code:%d\n", code);
      if (code == HTTP_CODE_OK)
      {
        String dat = http.getString();
        Serial.println(dat);
      }
    }
    else
    {
      Serial.printf("http get failed:%s\n", http.errorToString(code).c_str());
    }
    http.end();
  }

  delay(5000);
}
