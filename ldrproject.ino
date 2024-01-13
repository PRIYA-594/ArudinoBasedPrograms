int ldr=A0;//Set A0(Analog Input) for LDR.
int value=0;
void setup() {
Serial.begin(9600);
pinMode(9,OUTPUT);
}

void loop() {
value=analogRead(ldr);//Reads the Value of LDR(light).
Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
Serial.println(value);
if((value>1000)&&(value<7500))
  {
digitalWrite(3,1);
delay(100);

  
  }
  else if(value<300)
  {
    digitalWrite(9,HIGH);//Makes the LED glow in Dark.
  }
  else
  {
    digitalWrite(9,LOW);//Turns the LED OFF in Light.
  }
}
