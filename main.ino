#include <Wire.h>
#include <DFRobot_BMX160.h> //install it from library in Arduino IDE

// Create an instance of the BMX160 class
DFRobot_BMX160 bmx160;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Initialize I2C
  Wire.begin();

  // Initialize BMX160
  if (!bmx160.begin()) {
    Serial.println("BMX160 initialization failed!");
    while (1);
  }
  Serial.println("BMX160 initialization succeeded!");

  // Set gyroscope range
  bmx160.setGyroRange(eGyroRange_250DPS);

  // Set accelerometer range
  bmx160.setAccelRange(eAccelRange_4G);
}

void loop() {
  // Create instances to hold sensor data
  sBmx160SensorData_t magn;
  sBmx160SensorData_t gyro;
  sBmx160SensorData_t accel;
  
  // Get all sensor data
  bmx160.getAllData(&magn, &gyro, &accel);

  // Print accelerometer data
  Serial.print("Accel X: "); Serial.print(accel.x);
  Serial.print(" Y: "); Serial.print(accel.y);
  Serial.print(" Z: "); Serial.println(accel.z);

  // Print gyroscope data
  Serial.print("Gyro X: "); Serial.print(gyro.x);
  Serial.print(" Y: "); Serial.print(gyro.y);
  Serial.print(" Z: "); Serial.println(gyro.z);

  // Print magnetometer data
  Serial.print("Magn X: "); Serial.print(magn.x);
  Serial.print(" Y: "); Serial.print(magn.y);
  Serial.print(" Z: "); Serial.println(magn.z);

  // Add a delay for readability
  delay(1000);
}
