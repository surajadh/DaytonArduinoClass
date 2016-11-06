// the setup function runs once when you press reset or power the board
unsigned long packMillis = 0;
int pack1 = 0;
int pack2 = 0;
int pack3 = 0;
int numberOfLeds = 0;

void setup() {
  // initialize digital pin 13 as an output.

  Serial.begin(9600);
  Serial.println("Enter number of LEDs to be turned on:");

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);

}

// the loop function runs over and over again forever
void loop() {
  if (numberOfLeds > 12) {
    numberOfLeds = 12;
  }

  if (numberOfLeds < 0) {
    numberOfLeds = 0;
  }

  if (numberOfLeds / 4 > 0 || numberOfLeds == 4) {
    pack1 = 4;
    if (numberOfLeds / 4 > 1 || numberOfLeds == 8) {
      pack2 = 4;
      if (numberOfLeds / 4 > 2 || numberOfLeds == 12) {
        pack3 = 4;
      }
      else {
        pack3 = numberOfLeds % 4;
      }
    }
    else {
      pack2 = numberOfLeds % 4;
      pack3 = 0;
    }
  }
  else {
    pack1 = numberOfLeds % 4;
    pack2 = 0;
    pack3 = 0;
  }
//  Serial.print("pack1:");
//  Serial.print(pack1);
//  Serial.print(" pack2:");
//  Serial.print(pack2);
//  Serial.print(" pack3:");
//  Serial.print(pack3);
//  Serial.print("\n");


  // Pack1
//  Serial.println(millis() - packMillis);
  if (millis() - packMillis < 2) {
    turnOnLEDs(pack1);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  // Pack 2
  else if (millis() - packMillis < 4) {
    turnOnLEDs(pack2);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  // Pack 3
  else if (millis() - packMillis < 6) {
    turnOnLEDs(pack3);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  else if (millis() - packMillis > 6) {
    packMillis = millis();
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
}

void turnOnLEDs(int leds) {

  switch (leds) {
    case 0:
      {
//        Serial.println("Reached Case1");
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
      break;
    case 1:
      {
//        Serial.println("Reached Case1");
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
      break;
    case 2:
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
      break;
    case 3:
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
      }
      break;
    default:
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
      }
      break;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    numberOfLeds = Serial.parseInt();
    Serial.println(numberOfLeds);
  }
}

