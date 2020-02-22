#include <Arduino.h>
#include "WiFiFunctions.h"

void setupWiFi();

void setup(){
Serial.begin(115200);
setupWiFi();
// Serial.println()
}

void loop(){
}



void setupWiFi(){
    WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
    WiFi.onEvent(WiFiReady, SYSTEM_EVENT_WIFI_READY);
    WiFi.onEvent(WiFiStationStart, SYSTEM_EVENT_STA_START);
    WiFi.onEvent(WiFiStationStopped, SYSTEM_EVENT_STA_STOP);
    WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);
    WiFi.onEvent(WiFiStationGotIp, SYSTEM_EVENT_STA_GOT_IP);
    WiFi.mode(WIFI_OFF);
    WiFi.mode(WIFI_STA);
    WiFi.begin("OnePlus","qwerty.1234");
}

