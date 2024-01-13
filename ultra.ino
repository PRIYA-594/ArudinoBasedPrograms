const int ledPin=13;
const int trigPin=5;
const int echoPin=4;
const int ledontime=1000;
const int trigDistance=110;
int duration;
int distance;
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigPin,LOW);
  digitalWrite(trigPin,HIGH);
  delay(1);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;
  Serial.println(distance);
  if(distance<=trigDistance)
  {
    digitalWrite(ledPin,HIGH);
    delay(ledontime);
    digitalWrite(ledPin,LOW);
  }
  delay(100);
  Serial.println("blink");
}
