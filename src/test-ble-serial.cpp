#include <Arduino.h>
#include <M5Stack.h>
#include "BluetoothSerial.h"
 
BluetoothSerial SerialBT;
  
void setupM5 () {
  M5.begin(true, false, true);
  M5.Power.begin();
  

  // text print
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextColor(ORANGE);
  M5.Lcd.setCursor(10,10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Bluetooth test");
  M5.Lcd.setTextColor(RED);
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

unsigned long currTime;

void loop(){
  M5.update();

  currTime = millis();
  SerialBT.println("(" + String(currTime) + "ms)" + ": Hello World");
  delay(1000);
}
