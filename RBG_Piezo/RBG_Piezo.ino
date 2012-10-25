
const int red=9;
const int blue=10;
const int green=11;
int piezoValue;
int pause=10, redo=0, variance=0;
int timeDelay = 0;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(1));
  //setRGB(blue);
  //randomTransition(20);
  //setColor(0, 0, 255);
}

void loop()
{
  piezoValue = analogRead(0);
  Serial.println(piezoValue);
  while(piezoValue > 0 && redo == 0)
  {
    variance++;
    variance = variance%3;
    if(variance == 0)
    {
      setRGB(red);
    }
    if (variance == 1)
    {
      setRGB(blue);
    }
    if(variance == 2)
    {
      setRGB(green);
    }
    delay(200);
    redo = 1;
    timeDelay = 0;
  }
  redo = 0;
  delay(10);
  timeDelay++;
  if (timeDelay >= 3000)
  {
    setColor(0,0,0);
    delay(10);
  }
}

void setColor(int redLED, int greenLED, int blueLED)
{
  
  analogWrite(red,redLED);
  analogWrite(blue,blueLED);
  analogWrite(green,greenLED);
}

void transition(int colorNow, int colorChange, int colorNone, int timeDelay)
{
  int color1=255, color2=0, color3=0;
  for(int i=1;i<256;i++)
  {
    color1--;
    color2++;
    analogWrite(colorNow,color1);
    analogWrite(colorChange,color2);
    analogWrite(colorNone,color3);
    delay(timeDelay);
  }
}

void randomTransition(int delayTime)
{
  int random1=random(255);
  int random2=random(255);
  int random3=random(255);
  setColor(random1, random2, random3);
  delay(delayTime);
}

void colorWheel()
{
  transition(red,blue,green,pause);
  transition(blue,green,red,pause);
  transition(green,red,blue,pause);
}





void setRGB(int color)
{
  Serial.print("color = ");
  Serial.println(color);
  if(color == red)
  {
    setColor(255,0,0);
  }
  if(color == green)
  {
    setColor(0, 255,0);
  }
  if (color == blue)
  {
    setColor(0, 0, 255);
  }
}
  
