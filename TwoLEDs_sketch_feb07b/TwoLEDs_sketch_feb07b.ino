int ledPin1 = 10; // set to connec to arduino
int ledPin2 = 11;

int pot1 = A0; // matches the arduino board
int potRead = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // 9600 sets the speed limit between computer and arduino (baud rate can go up or down) tell the arduino send back information - e.g. read a sensor and send it back to a computer. The premise for most electronic devices.

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT); // oinMode is only for digital pins

}

void loop() {
  // put your main code here, to run repeatedly:

  //  digitalWrite(ledPin1, HIGH);
  //  digitalWrite(ledPin2, HIGH);

  // potRead = analogRead(pot1)/4;
  potRead = analogRead(pot1); 
  int mapped = map(potRead, 0,1023, 0,255);
  Serial.println(potRead);
  //analogWrite(ledPin1, potRead);
  analogWrite(ledPin1, mapped);

//  if (potRead < 512) {
//    analogWrite(ledPin1, 255);
//    analogWrite(ledPin2, 0);
//
//  } else {
//    analogWrite(ledPin2, 255);
//    analogWrite(ledPin1, 0);
//  }

}
