//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

  This program will test the LCD panel and the buttons
  Mark Bramwell, July 2010

  Modified the program to devlop a simple game
  Suraj Adhikari, Jan 2017

********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 5;
int adc_key_in  = 0;
int randomNumber = 0;
long currentTime = millis();
long buttonTime = millis();

int gasCarCursorLine1 = 0;
int gasCarCursorLine2 = 0;

bool line1Done = false;
bool line2Done = false;

int userCursorLine = 0;
int userCursorPosition = 0;

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

bool delay200ms() {
  if ((millis() - buttonTime) >= 200) {
    buttonTime = millis();
    return true;
  }
  return false;
}
// read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  // For V1.1 us this threshold
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 250)  return btnUP;
  if (adc_key_in < 450)  return btnDOWN;
  if (adc_key_in < 650)  return btnLEFT;
  if (adc_key_in < 850)  return btnSELECT;

  // For V1.0 comment the other threshold and use the one below:
  /*
    if (adc_key_in < 50)   return btnRIGHT;
    if (adc_key_in < 195)  return btnUP;
    if (adc_key_in < 380)  return btnDOWN;
    if (adc_key_in < 555)  return btnLEFT;
    if (adc_key_in < 790)  return btnSELECT;
  */


  return btnNONE;  // when all others fail, return this...
}

void setup()
{
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0, 0);
  lcd.print("R/L/U/D to move cursor");
  randomSeed(analogRead(A1));
}

void loop()
{
  lcd.setCursor(userCursorPosition, userCursorLine);
  lcd.cursor();
  if (millis() - currentTime > 2000) {
    currentTime = millis();
    lcd.clear();

    if (line1Done && line2Done) {
      lcd.print("ALL ELECTRIC");
      lcd.setCursor(0, 1);
      lcd.print(":: GO GREEN!!");
    }
    else {
      if (!line1Done) {
        gasCarCursorLine1 = random(16);
        lcd.setCursor(gasCarCursorLine1, 0);
        lcd.print("G");
      }
      else {
        lcd.setCursor(0, 0);
        lcd.print("GREEN");
      }

      if (!line2Done) {
        gasCarCursorLine2 = random(16);
        lcd.setCursor(gasCarCursorLine2, 1);
        lcd.print("G");
      }
      else {
        lcd.setCursor(0, 1);
        lcd.print("GREEN");
      }
    }
  }


  if (delay200ms()) {
    lcd_key = read_LCD_buttons();  // read the buttons
  }

  switch (lcd_key)
  {
    case btnRIGHT:
      {
        if (userCursorPosition == 15) {
          userCursorPosition = 0;
        } else {
          userCursorPosition = userCursorPosition + 1;
        }
        break;
      }
    case btnLEFT:
      {
        if (userCursorPosition == 0) {
          userCursorPosition = 15;
        } else {
          userCursorPosition = userCursorPosition - 1;
        }
        break;
      }
    case btnUP:
    case btnDOWN:
      {
        if (userCursorLine == 0) {
          userCursorLine = 1;
        }
        else {
          userCursorLine = 0;
        }
        break;
      }
    case btnSELECT:
      {
        if(userCursorLine == 0 && gasCarCursorLine1 == userCursorPosition) {
          line1Done = true;
        }
        if(userCursorLine == 1 && gasCarCursorLine2 == userCursorPosition) {
          line2Done = true;
        }
      }
  }
  lcd_key = 5;
}
