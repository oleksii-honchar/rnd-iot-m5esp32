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
  M5.Lcd.println("Bluetooth & buttons test");
  M5.Lcd.setTextColor(RED);
} 

void setupBle() {
  Serial.begin(115200);

  if (!SerialBT.begin("M5Stack:ESP32")) {
    Serial.println("[setupBle] An error occurred initializing Bluetooth");
  } else {
    Serial.println("[setupBle] Bluetooth initialized");
    SerialBT.println("Hello World!");
  }
}

void setup() {
  setupM5();
  setupBle();
}

unsigned long currTime;

void loop(){
  M5.update();

  // currTime = millis();
  // SerialBT.println("(" + String(currTime) + "ms)" + ": Hello World");
  // delay(1000);

  if (M5.BtnA.wasReleased()) {
    M5.Lcd.print('A');
    SerialBT.println("'A' button was pressed");
  } else if (M5.BtnB.wasReleased()) {
    M5.Lcd.print('B');
    SerialBT.println("'B' button was pressed");
  } else if (M5.BtnC.wasReleased()) {
    M5.Lcd.print('C');
    SerialBT.println("'C' button was pressed");
  }
}
