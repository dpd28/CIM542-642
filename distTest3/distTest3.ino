
// Testing the Parallax PING distance sensor with LEDs …
// THIS WORKED!!!

const int pingPin = 12; //setup pingpin as 12

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
// set up these pins as outputs

pinMode(3, OUTPUT); // GREEN LED
pinMode(5, OUTPUT); // YELLOW LED 1
pinMode(7, OUTPUT); // RED LED


digitalWrite(3, HIGH);  

digitalWrite(5, HIGH);

digitalWrite(7, HIGH);
delay (500);

digitalWrite(3, LOW);

digitalWrite(5, LOW);

digitalWrite(7, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);

  
if (inches < 20) {
  digitalWrite(3, HIGH); // ON
  Serial.println("GO GO GREEN");
  }
if (inches > 20) {
  digitalWrite(3, LOW); // OFF
 }
 
if (inches < 5) {
    digitalWrite(5, HIGH);
    Serial.println("Yellow WOW");    
    }
if (inches >5)  {
    digitalWrite(5, LOW);
    Serial.println("Yellow Meh");
    }
   
if (inches < 2) {
    digitalWrite(7, HIGH);
    Serial.println("RED HOT");
    }
if (inches > 2) {
    digitalWrite(7, LOW);
    }
 
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
