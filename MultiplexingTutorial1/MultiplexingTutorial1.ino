const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int pack1 = 6;
const int pack2 = 7;
const int pack3 = 8;

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
  // Lets turn bottom 5 LEDs ON
  // Look at diagram to understand Pack 1, Pack 2 and Pack 3
  // How many LEDs in Pack 1 would you like to turn ON
  // Pack 1 block
  digitalWrite(led1, HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(pack1, LOW);
  digitalWrite(pack2, HIGH);
  digitalWrite(pack3, HIGH);
 // .
  // .
  delay(1);
  // .
  // Send LOW in Pack 1 ground and HIGH in Pack 2 and Pack 3 grounds respectively
  // Add delay of 1s for now to see how it will look
//  delay(1000);  
  digitalWrite(led1, HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  // How many LEDs in Pack 2 would you like to turn ON
  // Pack 2 block
  // .
  // .
  // .
  digitalWrite(pack1, HIGH);
  digitalWrite(pack2, LOW);
  digitalWrite(pack3, HIGH);

  delay(1);
 }

  // Identify how many LEDs in Pack 3 would need to be on
  
  // Now keep on decreasing delay and find out what delay would make our eyes feel that all LEDs are ON
  

