/*
===============================================================================================================
QMC5883LCompass.h Library XYZ Example Sketch
Learn more at [https://github.com/mprograms/QMC5883LCompass]

This example shows how to get the XYZ values from the sensor.

===============================================================================================================
Release under the GNU General Public License v3
[https://www.gnu.org/licenses/gpl-3.0.en.html]
===============================================================================================================
*/
#include "SoftwareI2C.h"  
SoftwareI2C WireS1;

#include <QMC5883LCompass.h>
QMC5883LCompass compass;

void setup() {
  Serial.begin(2000000);

  compass.initSoftwareI2C(&WireS1, 3, 2);     // initSoftwareI2C, sda, scl
  compass.init();
//  compass.setCalibration(-1180, 1192, -1777, 651, -1136, 1233);
  compass.setCalibration(-1333, 1112, -1800, 590, -1110, 1350);
  // Define OSR = 512, Full Scale Range = 8 Gauss, ODR = 200Hz, set continuous measurement mode
  compass.setMode(0x01, 0x0C, 0x10, 0x00);   // compass.setMode(MODE, ODR, RNG, OSR);
  compass.setSmoothing(10,true);  
}

void loop() {
//  int x, y, z;
  
  // Read compass values
  compass.read();

  // Return XYZ readings
//  x = compass.getX();
//  y = compass.getY();
//  z = compass.getZ();

  Serial.print("Azimuth: ");
  Serial.println(compass.getAzimuth());
//  
//  Serial.print(" X: ");
//  Serial.print(compass.getX());
//  Serial.print(" Y: ");
//  Serial.print(compass.getY());
//  Serial.print(" Z: ");
//  Serial.print(compass.getZ());
//  Serial.println();
  
//  delay(10);

  delay(1);
}
