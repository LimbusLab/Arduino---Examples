
/*
  3 Axis Accelerometer!

  Code written by: ElectricSlim (www.ElectricSlim.net)

  This is a basic code that prints the values of the 3 directions (X,Y, and Z)
  to the Serial Monitor. Use this code to gain wisdom in the predicament that
  is gravity. 
  
  */


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  Serial.print("x = ");
  Serial.println(analogRead(0));
  Serial.print("y = ");
  Serial.println(analogRead(1));
  Serial.print("z = ");
  Serial.println(analogRead(2));
  delay(100);
}
