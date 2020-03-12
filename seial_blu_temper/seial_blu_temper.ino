/*Program to control LED (ON/OFF) from ESP32 using Serial Bluetooth
 * Thanks to Neil Kolbans for his efoorts in adding the support to Arduino IDE
 * Turotial on: www.circuitdigest.com 
 */

#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino

BluetoothSerial ESP_BT; //Object for Bluetooth


void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32_TEMP"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");
  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}

void loop() {
      float c = random(35.0,40.0);
      ESP_BT.println(c);    
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
      delay(750);  
}
