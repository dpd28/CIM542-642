// First find the range of the audio with Gemma

int audioIn = A1;
int audioRead = 0;

// set limits?
//int lowRange
//int highRange


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  audioRead = analogRead(audioIn);
  Serial.println(audioRead);

  // analog inputs 0-1023
  // analog outputs analogWrite 0-255 / map or float
  
}
