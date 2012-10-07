/*
  Sensor Wall!

  Code written by: ElectricSlim (www.ElectricSlim.net)

  This is the code used to run the Sensor Wall. Each sensor is read with the 
  analogRead command but their values change from sensor to sensor and 
  therefore the servo output will react differently. 
  
  */


#include <Servo.h>

Servo myservo;

int pos=0, sensorReading, oldReading=0;

void setup()
{
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(180);
}


void loop()
{
  sensorReading = analogRead(0);
  /*Serial.print("Sensor = ");
  Serial.println(sensorReading);*/
  sensorReading = map(sensorReading, 0, 1023, 180, 30);
  Serial.print("Servo Location = ");
  Serial.println(sensorReading);
  if (abs(sensorReading-oldReading) <= 3)
  {
    delay(10);
    Serial.println("DELAYED");
  }
  else
  {
    myservo.write(sensorReading);
    Serial.println("IT IS WRITTEN!");
  }
  oldReading = sensorReading;
  delay(10);
  
}
