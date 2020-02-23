#ifndef MAIN_H
#define MAIN_H
#include <Arduino.h>    
#include <WiFi.h>
extern TaskHandle_t Task1;
extern uint8_t name;

void WiFiStationConnected(WiFiEvent_t, WiFiEventInfo_t);
void WiFiReady(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationStart(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationStopped(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationDisconnected(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationGotIp(WiFiEvent_t, WiFiEventInfo_t);
void setupWiFi();
void animate(void* pvParameters);

#endif