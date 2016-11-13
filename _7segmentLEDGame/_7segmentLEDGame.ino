int count = 0;
unsigned long timer = 0L;
String userInput;
bool winner = false;
bool newData = false;
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

void setup() {
  Serial.begin(9600);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  if (newData && userInput >= "0" ) {
    newData = false;
    Serial.println(userInput);
    int inputNumber = userInput.toInt();
    if (inputNumber == count) {
      displayWinAnimation();
      delay(500);
      displayWinAnimation();
      delay(500);
    } else {
      displayLooseAnimation();
      delay(500);
      displayLooseAnimation();
      delay(500);
    }
    count = 0;
    timer = millis();
    userInput = "";
  }

  if (millis() - timer > 200) {
    if (count < 9) {
      count = count + 1;
    }
    else {
      count = 0;
    }
    timer = millis();
  }

  // Read command from serial port
  displayNumber(count);
}

void displayNumber(int number) {
  switch (number) {
    case 1:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 2:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, LOW);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 3:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, HIGH);
      break;
    case 4:
      digitalWrite(a, LOW);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 5:
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 6:
      //do something when var equals 2
      digitalWrite(a, HIGH);
      digitalWrite(b, LOW);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 7:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, LOW);
      digitalWrite(e, LOW);
      digitalWrite(f, LOW);
      digitalWrite(g, LOW);
      break;
    case 8:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    case 9:
      //do something when var equals 2
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, LOW);
      digitalWrite(f, HIGH);
      digitalWrite(g, HIGH);
      break;
    default:
      digitalWrite(a, HIGH);
      digitalWrite(b, HIGH);
      digitalWrite(c, HIGH);
      digitalWrite(d, HIGH);
      digitalWrite(e, HIGH);
      digitalWrite(f, HIGH);
      digitalWrite(g, LOW);
      break;
  }
}

void displayWinAnimation() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(a, HIGH);
  delay(100);
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  delay(100);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  delay(100);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  delay(100);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  delay(100);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  delay(100);
}

void displayLooseAnimation() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(f, HIGH);
  delay(100);
  digitalWrite(g, HIGH);
  delay(100);
  digitalWrite(c, HIGH);
  delay(100);
  digitalWrite(b, HIGH);
  delay(100);
  digitalWrite(g, HIGH);
  delay(100);
  digitalWrite(e, HIGH);
  delay(100);
}

void serialEvent() {
  while (Serial.available()) {
    // get the new number:
    newData = true;
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if(inChar != '\n') {
      userInput += inChar;
    }
  }
}


