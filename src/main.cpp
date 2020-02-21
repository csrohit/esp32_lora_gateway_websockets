#include <Arduino.h>
#include <WiFi.h>
#include <FastLED.h>

//* function definition
void setupWiFi();
void ledAnimation(uint8_t);

//* Fast led
#define DATA_PIN 13
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];

//* WiFi
const char* ssid = "OnePlus";
const char* pwd = "qwerty.1234";


void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  setupWiFi();


}

void loop() {
}

void setupWiFi(){
  unsigned long this_start = millis();
  WiFi.mode(WIFI_STA);
  Serial.printf("Connecting to %s\t", ssid);
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED && millis()-this_start < 20000){
    Serial.print(".");
    ledAnimation(1);
  }
  if (WiFi.status() == WL_CONNECTED) {
  leds[0] = CRGB::Green;
  FastLED.show();
    Serial.printf("\nConnected to %s\n", ssid);
    Serial.print(F("IP address  :"));Serial.print(WiFi.softAPIP());
    Serial.print(F("\tMAC address :"));Serial.println(WiFi.softAPmacAddress());
  }else{
    leds[0] = CRGB::Red;
    FastLED.show();
    WiFi.disconnect();
    Serial.println(F("WiFi disconnected"));
  }
}

void ledAnimation(uint8_t count=0){
  while (count--)
  {
      for(uint8_t i=0; i<255;i++){
      leds[0].setHue(i);
      FastLED.show();
    }
  }
}