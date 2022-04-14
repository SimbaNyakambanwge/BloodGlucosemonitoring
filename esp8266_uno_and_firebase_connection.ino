
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "finalproject-d3ec7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "PgzhysdZC33WwHmoodufmTjXeZpT6I1gG4n52bRC"
#define WIFI_SSID "SKYZFQNT"
#define WIFI_PASSWORD "vEHuNZiMYIgZ"

void setup() {
  Serial.begin(115200);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
String firebaseReading;

void loop() {

if (Serial.available()) {
Serial.write(Serial.read());
firebaseReading = Serial.read();

}
 
 Firebase.pushString("/BloodGlucose/Reading", firebaseReading);
 delay(500);
   if (Firebase.failed()) 
    {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
  }
  delay(1000);
}
