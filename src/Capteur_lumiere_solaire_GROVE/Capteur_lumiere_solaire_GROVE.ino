/*
    ** Mesure multicanal lumière visible,IR et UV sur une plage de 280 à 950 nm, module Grove **
       PIN I2C Module shield GROVE
       Moniteur série -> Baud rate 115200.
*/

#include <Wire.h>

#include "Arduino.h"
#include "SI114X.h"

SI114X SI1145 = SI114X();

void setup() {
  Serial.begin(115200);
  while (!SI1145.Begin()) {
    delay(2000);
  }
}

void loop() {
  Serial.print("Lumière visible : ");
  Serial.println(SI1145.ReadVisible());
  Serial.print("Lumière IR : ");
  Serial.println(SI1145.ReadIR());
  Serial.print("Lumière UV : ");
  Serial.println((float)SI1145.ReadUV() / 100);
  Serial.println("--------------------------------------");
  delay(1000);
}
