#include <Arduino.h>
#include <ArduinoWebsockets.h>
#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>

void setupLora();
void setupWiFi();
void onnReceive();
void setupSockets();

const char* ssid = "Room no 13";
const char* pwd = "roomno13";

const char* websockets_server_host = "192.168.0.10";
const uint16_t websockets_server_port = 8080;

short ssPin = 5;
short dio0  = 2;
short RST   = 14;

using namespace websockets;
WebsocketsClient client;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver Callback");
  setupWiFi();
  setupSockets();
  setupLora();


}

void loop() {
  // do nothing
}

void onReceive(int packetSize) {
  Serial.print("Received packet '");
  for (int i = 0; i < packetSize; i++) {
    Serial.print((char)LoRa.read());
  }
  Serial.print("' with RSSI ");
  Serial.println(LoRa.packetRssi());
}



void setupLora(){
  Serial.println(F("Trying to Setup LoRa Module with"));
  Serial.printf("CS=GPIO%d  DIO0=GPIO%d  Reset= GPIO%d\n", ssPin, dio0, RST);
  LoRa.setPins(ssPin, RST, dio0);
  if (!LoRa.begin(433E6)) {
      Serial.println("Starting LoRa failed!");
      while (1);
    }
  // LoRa.setSyncWord(0xf3);
  Serial.println(F("Lora started"));
  LoRa.onReceive(onReceive);
  LoRa.receive();
}
void setupWiFi(){
  unsigned long this_start = millis();
  WiFi.mode(WIFI_STA);
  Serial.printf("Connecting to %s\t", ssid);
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED && millis()-this_start < 20000){
    Serial.print(".");
    delay(500);
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("\nConnected to %s\n", ssid);
    Serial.print(F("IP address  :"));Serial.print(WiFi.softAPIP());
    Serial.print(F("\tMAC address :"));Serial.println(WiFi.softAPmacAddress());
  }else{
    WiFi.disconnect();
    Serial.println(F("WiFi disconnected"));
  }
}

void setupSockets(){
  bool connected = client.connect(websockets_server_host, websockets_server_port, "/");
  if(connected) {
      Serial.println("Connecetd!");
      client.send("Hello Server");
  } else {
      Serial.println("Not Connected!");
  }

  // run callback when messages are received
  client.onMessage([&](WebsocketsMessage message){
      Serial.print("Got Message: ");
      Serial.println(message.data());
  });
}