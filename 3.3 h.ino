#include "PDMSerial.h"
PDMSerial pdm;

int sensorPin = A0;
int ledPin = 10;
int sensorData = 0;
int scaledSensor;

void setup() {
    pinMode(sensorPin, INPUT);
    
    Serial.begin(9600);
    
}

void loop() {
    sensorData = analogRead(sensorPin);
    scaledSensor = map(sensorData, 0, 1023, 0, 255);
    
    pdm.transmitSensor("a0", scaledSensor);
    pdm.transmitSensor("end");
    
    boolean newData = pdm.checkSerial();
    if(newData){
      if(pdm.getName().equals(String("mouse"))){
        int ledBright = map(pdm.getValue(), 0, 600,0, 255);
        analogWrite(ledPin, ledBright);
      }
    }
}
