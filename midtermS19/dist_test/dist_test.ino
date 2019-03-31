// Tutorial: https://www.arduino.cc/en/Tutorial/Ping

int distPin = 7; //change to 8 from 7 to test - OK, still not working :-(

// Testing the Parallax PING distance sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, inches, cm;

  pinMode(distPin,LOW);
  delayMicroseconds(2);
  digitalWrite(distPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(distPin, LOW);

// read the pulse from the same pin
pinMode(distPin, INPUT);
duration = pulseIn(distPin, HIGH);

inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(1000);

}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
  }

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
  
}
