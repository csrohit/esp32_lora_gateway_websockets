
#include "main.h"
void setup(){
    // xTaskCreate(animate, "blinkTask", 1000,NULL,0,&Task1);
    Serial.begin(115200);
    setupWiFi();
    name=10;
// Serial.println()
}

void loop(){
}


void animate(void* pvParameters){
    while(true){
        Serial.println(F("not connected"));
        vTaskDelay(500);
    }
    
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

