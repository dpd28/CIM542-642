// analog input to output
// test the analog sensor - baseline test is important. Find your ideal range

int tonePin = 8;
int photoPin = A0;
int photoRead = 0;
// always set a high and a low limit

int lowLimit = 30;
int highLimit = 600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 // this is input
 photoRead = analogRead(photoPin);


 // need a way to limit the program run. Ensures no matter the light
 if(photoRead < lowLimit) {
  photoRead = lowLimit;
  }

  if(photoRead > highLimit){
    photoRead = highLimit;
  }

   int mapped = map(photoRead, 0, 350, 31, 4978);
 Serial.println(photoRead);
 
 //output
 tone(tonePin,mapped,100);
}
