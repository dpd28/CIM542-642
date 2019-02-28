int ledpin1 = 3;
int counter = 0;

long prevMillis = 0;
int interval = 10;

boolean flipFlop = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledpin1, counter);
//confirm that 10 milliseconds have passed, then save the last time that we confirmed that
  if (millis() - prevMillis >= interval){
    prevMillis = millis(); // 10ms have passed!

    if(flipFlop == false){
  counter = counter + 1;  
      }else {
        counter = counter - 1;
        }
   // increase the counter by 1; max is 255 brightness
  // counter = counter + 1; // always look for establish a limit   
  // create a pendulum action use a boolean statement
 
    }

  if(counter >= 255){
    flipFlop = true;
    //counter = 0;
    }

  if(counter <= 0) {
      flipFlop = false;
      }
}

//    delay(10);
