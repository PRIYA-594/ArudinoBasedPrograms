#include<Servo.h>
Servo myser;
int pos=0;
void setup()
{
  myser.attach(9);
}
void loop()
{
for(pos=0;pos<180;pos+=1)
{
  myser.write(pos);
  delay(0);
}

for(pos=180;pos>=1;pos-=1)
{
  myser.write(pos);
  delay(0);
}

}
