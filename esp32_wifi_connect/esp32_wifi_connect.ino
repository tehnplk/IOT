#include <WebSockets.h>
#include <WebSocketsClient.h>
#include <WebSocketsServer.h>

#include "WiFi.h"
 
const char* ssid = "net-kak";
const char* password =  "11223344";

const uint16_t port = 19009;
const char* host = "203.157.118.123";

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t* payload, size_t length)
{
  switch (type)
  {
  case WStype_DISCONNECTED:
    
    break;
  case WStype_CONNECTED:
    
    webSocket.sendTXT("Connected\r\n");
    break;
  case WStype_TEXT:
    
    break;
  case WStype_BIN:
    
    break;
  }
}
 
void setup() {
 
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Try to Connecting Wifi.");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

  webSocket.begin("203.157.118.123", 19009, "/sc1/A001");
  webSocket.onEvent(webSocketEvent);
 
  
 
}

void blink(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);  
}
 
void loop() {

  WiFiClient client;
  blink();
  
}
