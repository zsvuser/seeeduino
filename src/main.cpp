#include <Arduino.h>
#include <Wire.h>
#include "Seeed_BME280.h"

BME280 bme280;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  if(!bme280.init()){
    Serial.println("Device error!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  float pressure;

  //get and print temperatures
  Serial.print("Temp: ");
  Serial.print(bme280.getTemperature());
  Serial.println("C");//The unit for  Celsius because original arduino don't support speical symbols

  //get and print atmospheric pressure data
  Serial.print("Pressure: ");
  Serial.print(pressure = bme280.getPressure());
  Serial.println("Pa");

  //get and print altitude data
  Serial.print("Altitude: ");
  Serial.print(bme280.calcAltitude(pressure));
  Serial.println("m");

  //get and print humidity data
  Serial.print("Humidity: ");
  Serial.print(bme280.getHumidity());
  Serial.println("%");

  delay(1000);
}