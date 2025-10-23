/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  NOTE: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#define BLYNK_TEMPLATE_ID "TMPL3O7sdQCkT"
#define BLYNK_TEMPLATE_NAME "Weather monitoring"
#define BLYNK_AUTH_TOKEN "MMR7ZkK1F79TxIQNC-6Gxz8i7I0vkU7H"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define dhtpin 4
#define dhtType 11
#define led 2
BlynkTimer timer;
#define AOUT_PIN 36;

DHT dht(dhtpin, dhtType);

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "33";
char pass[] = "Protagonist";
int flag = 0;

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();  
  Serial.print("V2 Slider value is: ");
  Serial.println(pinValue);
  digitalWrite(led,pinValue);
}

void sendSensor() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  if (t > 29 && flag == 0) {
    Serial.println("Temperature rised above 29C");
    Blynk.logEvent("temp_alert", String("High Temperature Detected! Tº: ") + t);
    flag = 1; // Set the flag to indicate that an alert has been sent
  }
  else if (t <= 29 && flag == 1) {
    flag = 0; // Reset the flag when temperature drops back to 29C or below
  }
    int adcValue = analogRead(AOUT_PIN);  //Moisture sensor reading
   float m = map(adcValue, 0, 4095, 100, 0);
   delay(100);
   Serial.println();
   Blynk.virtualWrite(V3,adcValue);
}


void setup() {
  // Debug console
  Serial.begin(115200);
  dht.begin();
  pinMode(led,OUTPUT);
  timer.setInterval(1000L, sendSensor);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  timer.run();
}
