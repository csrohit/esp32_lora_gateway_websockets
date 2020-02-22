#include "WiFiFunctions.h"


void WiFiReady(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.println(F(" WiFi is ready"));
}
void WiFiStationStart(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.println(F(" WiFi station started"));
}
void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.print(F("Connected:\n\tSSID: "));
    for(uint8_t i=0; i< info.connected.ssid_len; i++)
        Serial.print((char)info.connected.ssid[i]);
    Serial.print(F("\n\tBSSID: "));
    for (uint8_t i = 0; i < 6; i++){
        Serial.printf("%02X", info.connected.bssid[i]);
        if(i<5){
            Serial.print(":");  
        }
    }
    Serial.printf("\n\tChannel: %u\n\tAuthMode: %u\n", info.connected.channel, info.connected.authmode);
}
void WiFiStationGotIp(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.print(F("Got IP: "));
    Serial.print(IPAddress(info.got_ip.ip_info.ip.addr));
    Serial.print(F("\tNetmask: "));
    Serial.print(IPAddress(info.got_ip.ip_info.netmask.addr));
    Serial.print(F("\tGatweway: "));
    Serial.print(IPAddress(info.got_ip.ip_info.gw.addr));   
    Serial.println();
}
void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.print(F(" Disconnected from AP => \n\tSSID: "));
    for(uint8_t i=0; i< info.disconnected.ssid_len; i++)
        Serial.print((char)info.disconnected.ssid[i]);
    Serial.print(F("\n\tBSSID: "));
    for (uint8_t i = 0; i < 6; i++){
        Serial.printf("%02X",info.disconnected.bssid[i]);
        if(i<5){
            Serial.print(":");
        }
    }
    Serial.print(F("\n\tReason: "));
    switch (info.disconnected.reason)
    {
    case WIFI_REASON_NO_AP_FOUND:
        Serial.println(F("AP not found\n\tStopping WiFi..."));
        WiFi.mode(WIFI_OFF);
        break;
    case WIFI_REASON_AUTH_LEAVE:
        Serial.println(F("AP LEAVE\n\tStopping WiFi..."));
        WiFi.mode(WIFI_OFF);
        break;
    case WIFI_REASON_AUTH_FAIL:
        Serial.println(F("AUTH FAIL\n\tStopping WiFi..."));
        WiFi.mode(WIFI_OFF);
        break;
    default:
        Serial.println(info.disconnected.reason);
        WiFi.mode(WIFI_OFF);
        break;
    }
}
void WiFiStationStopped(WiFiEvent_t event, WiFiEventInfo_t info){
    Serial.printf("(%lu) ", millis());
    Serial.println(F(" WiFi station stopped"));
}