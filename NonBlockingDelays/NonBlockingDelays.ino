// Blocking delays will stop the program and do nothing during delay
// Non blocking delays will just delay program block execution but
// we can also do other tasks and we do not have to block other tasks
// Main function we use to do this is called millis()

// Each time we run millis() we will get a different value. It is 0 when arduino and restarted
// each time we read millis() it returns the time elapsed since the Arduino is restarted and
// rolls over and becomes 0 after that about 50 days.

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int pack1 = 6;
unsigned long previousMillis;
const int interval = 1000;
int ledState = LOW;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pack1, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(millis() - previousMillis > interval) {
    // set value of previousMillis to millis()
    // if(ledState == LOW) {
    //   ledState = HIGH;
    // } else 
    // .
    // .
    // .
    
      
  }
  // .
  // .
  // .
  digitalWrite(pack1, LOW);
  // .
  // .
  // .
  
}

