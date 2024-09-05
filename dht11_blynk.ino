#define BLYNK_TEMPLATE_ID "TMPL3dzABl1-J"
#define BLYNK_TEMPLATE_NAME "dht"
#define BLYNK_AUTH_TOKEN "QVpgo-x84YLu39O90hMyXPDn4kbOGfV_"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = BLYNK_AUTH_TOKEN;  //Enter your Blynk Auth token
char ssid[] = "AndroidShare_M2";  //Enter your WIFI SSID
char pass[] = "indhu14052005";  //Enter your WIFI Password
double T, P;
char status;

DHT dht(D4, DHT11);
BlynkTimer timer;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
   dht.begin();
timer.setInterval(100L, DHT11sensor);
}

void loop() {

Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);


}
