#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 3

unsigned long int currentTime;
unsigned int seconds = 0;
unsigned int minutes = 0;
uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };

TM1637Display display(CLK, DIO);

void setup()
{
  // Setup serial with baud rate of 9600
  currentTime = millis();
  display.setBrightness(0x08);
  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(0);
  data[2] = display.encodeDigit(0);
  data[3] = display.encodeDigit(0);
}

void loop()
{
  // Read serial for current time
  // Set brightness
  if(millis() - currentTime > 1000) {
    currentTime = millis();
    if(seconds == 59) {
      seconds = 0;
      if(minutes == 59) {
        minutes = 0;
      }
      else {
        minutes = minutes + 1;  
      }
    } else {
      seconds = seconds + 1;
    }
  }
  data[0] = display.encodeDigit(minutes / 10);
  data[1] = 0x80 | display.encodeDigit(minutes % 10);
  data[2] = display.encodeDigit(seconds / 10);
  data[3] = display.encodeDigit(seconds % 10);
  display.setSegments(data);
}

