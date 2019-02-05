int button1 = 2;
int led1 = 11;

void setup() {
  // put your setup code here, to run once:

pinMode(button1,INPUT);
pinMode(led1,OUTPUT);

Serial.begin(9600); // refers to the speed limit - communication between computer and arduino

}

void loop() {
  // put your main code here, to run repeatedly:

int button = digitalRead(button1);
Serial.print("button1: "); // a way to keep track of what is happening; their values
Serial.println(button);
Serial.println(button);
digitalWrite (led1,button);





}
