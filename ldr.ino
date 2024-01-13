const int ledPin = 13;
const int ldrPin = A0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 400)
  {
    digitalWrite(ledPin, 255);
    Serial.print("Its Dark, Turn on the LED:");
    Serial.println(ldrStatus);

  }
  else
  {
    digitalWrite(ledPin, 0);
    Serial.print("Its Bright, Turn off the LED:");
    Serial.println(ldrStatus);
  }

}
