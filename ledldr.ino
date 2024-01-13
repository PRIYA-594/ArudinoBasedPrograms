int sensor=A0;
int output=3; 
void setup()                                                          
{
pinMode(output, OUTPUT);                                                
}
void loop()
{ 
int reading=analogRead(sensor);
int bright;       
if(reading<300)
{
  bright=reading/2;
  analogWrite(output,HIGH);                                   
}
else if(reading>300 && reading<800)
{
  bright=reading/4;
  analogWrite(output,bright);  
  
}
else
{
  digitalWrite(output,LOW);
}
}
