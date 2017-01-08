//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

unsigned long int currentTime;
unsigned int seconds = 0;
unsigned int minutes = 34;
unsigned int hours = 6;


void setup()
{
  currentTime = millis();
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0, 0);
  lcd.print("Current Time"); // print a simple message
}

void loop()
{
  if (millis() - currentTime > 1000) {
    currentTime = millis();
    if (seconds == 59) {
      seconds = 0;
      if (minutes == 59) {
        minutes = 0;
        if(hours == 23) {
          hours = 0;
        }
        else {
          hours = hours + 1;
        }
      }
      else {
        minutes = minutes + 1;
      }
    } else {
      seconds = seconds + 1;
    }
  }
  
  lcd.setCursor(0, 1);           // move to the begining of the second line
  lcd.print(hours);
  lcd.print(":");
  lcd.print(minutes);
  lcd.print(":");
  
  if(seconds < 10) {
    lcd.print(0);
  }
  
  lcd.print(seconds);      // display seconds elapsed since power-up
}

