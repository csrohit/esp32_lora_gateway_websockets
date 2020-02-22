#ifndef WIFIFUNCTIONS_H 
#define WIFIFUNCTIONS_H
#include <WiFi.h>
  

void WiFiStationConnected(WiFiEvent_t, WiFiEventInfo_t);
void WiFiReady(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationStart(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationStopped(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationDisconnected(WiFiEvent_t, WiFiEventInfo_t);
void WiFiStationGotIp(WiFiEvent_t, WiFiEventInfo_t);
  
#endif 