void setup() {
  // put your setup code here, to run once:

  pinMode(11,OUTPUT); // turns pin 11 into an output pin. this outlet is live.

}


// CODING AREA


void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(11,HIGH);
  delay(1000);
 digitalWrite(11,LOW);
  delay(1000);
// digitalWrite(13,HIGH);
//  delay(50);
// digitalWrite(13,LOW);
//  delay(100);
}
