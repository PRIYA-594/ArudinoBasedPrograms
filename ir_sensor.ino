int sensor=2;
int LED=13;
void setup()
{
pinMode(sensor,INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600);

}
void loop()
{
  int statussensor=digitalRead(sensor);
  if(statussensor==1)
 { 
  digitalWrite(LED,LOW);
  
 }
   else
   {
  digitalWrite(LED,HIGH);
   }
delay(500);
Serial.println(sensor);

}
