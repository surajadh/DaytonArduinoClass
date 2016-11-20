#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 3

TM1637Display display(CLK, DIO);

void setup()
{
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x08);
  display.setSegments(data);
}

void loop()
{
  int k;
//  uint8_t data[] = { SEG_A | SEG_D | SEG_E | SEG_F, SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F, SEG_E | SEG_F | SEG_D, SEG_B | SEG_C | SEG_D | SEG_E | SEG_G };

//  display.setBrightness(0x08);
//  display.setSegments(data);
  
  // All segments on

  // -------------------------
  // Displaying numbers
//  data[1] = display.encodeDigit(1);
//  data[2] = display.encodeDigit(2);
  
//  display.setSegments(data+1, 2, 2);
//  display.showNumberDec(0, true, 4, 0);
//  display.setSegments(data);
//  display.showNumberDec(4, false);
//  display.showNumberDec(22, false, 1, 3);
  
  while(1);
}
