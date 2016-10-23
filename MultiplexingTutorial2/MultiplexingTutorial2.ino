// We will write similar program to tutorial 1 but this time we will use millis
// instead of delays

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int pack1 = 6;
const int pack2 = 7;
const int pack3 = 8;
unsigned long packMillis = 0;
int intervalBetweenPacks = 2;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pack1, OUTPUT);
  pinMode(pack2, OUTPUT);
  pinMode(pack3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(millis() - packMillis < 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);  
  }
  else if(millis() - packMillis < 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  else if(millis() - packMillis < 6) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  else if(millis() - packMillis > 6) {
    packMillis = millis();
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}
