#define TINY_BME280_I2C
#include "TinyBME280.h"
tiny::BME280 mySensor;

void setup()
{
  Serial.begin(9600);
  Serial.println("Reading basic values from BME280");

  mySensor.setI2CAddress(0x76);

  if (mySensor.begin() == false) //Begin communication over I2C and Address 0x77
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
}

void loop()
{
  Serial.print(F("Temperature in Celsius:\t\t"));
  Serial.println(mySensor.readFixedTempC() / 100.0); //Output value of "5123" equals 51.23 DegC.

  Serial.print(F("Temperature in Fahrenheit:\t"));
  Serial.println(mySensor.readFixedTempF() / 100.0); //Output value of "7470" equals 74.70 DegF.

  Serial.print(F("Humidity in %:\t\t\t"));
  Serial.println(mySensor.readFixedHumidity() / 1000.0); //Output value of "47445" represents 47.445 %RH

  Serial.print(F("Pressure in hPa:\t\t"));
  Serial.println(mySensor.readFixedPressure() / 100.0); //Output value of "96386" equals 96386Pa = 963.86 hPa

  Serial.println();

  delay(1500);
}


[env:env1]
platform = atmelavr
board = ATmega328P
framework = arduino
lib_deps = fabyte/Tiny BME280@^1.0.2


[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps = fabyte/Tiny BME280@^1.0.2

