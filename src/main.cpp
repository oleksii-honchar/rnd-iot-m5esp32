#include <M5Stack.h>
#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
  
void setupM5 () {
  M5.begin();
  M5.Power.begin();
  

  // text print
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(ORANGE);
  M5.Lcd.setCursor(10,10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Bluetooth test");
} 

void setupBle() {
  Serial.begin(115200);

  if (!SerialBT.begin("M5Stack:ESP32")) {
    Serial.println("[setupBle] An error occurred initializing Bluetooth");
  } else {
    Serial.println("[setupBle] Bluetooth initialized");
  }
}

void setup() {
  setupM5();
  setupBle();
}

void loop(){
  SerialBT.println("Hello World");
  delay(1000);
}
