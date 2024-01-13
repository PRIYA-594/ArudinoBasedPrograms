#include<Servo.h>
Servo myser;
void setup()
{
  myser.attach(9,600,2300);
}
void loop()
{
myser.write(0);
delay(1000);
myser.write(90);
delay(500);
myser.write(135);
delay(500);
myser.write(0);
delay(1500);
}
