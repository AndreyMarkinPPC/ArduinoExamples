/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, rw = 11, en = 2, d0 = 3, d1 = 4, d2 = 5, d3 = 6, d4 = 7, d5 = 8, d6 = 9, d7 = 10;
LiquidCrystal lcd(rs, rw, en, d0, d1, d2, d3, d4, d5, d6, d7);

//byte heart[8] = {
//  0b00000,
//  0b01010,
//  0b11111,
//  0b11111,
//  0b11111,
//  0b01110,
//  0b00100,
//  0b00000
//};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
//  lcd.createChar(0, heart);
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("  Sama monstr");
//  lcd.write(byte(0));
//  lcd.write(byte(0));
//  lcd.write(byte(0));
//  lcd.write(byte(0));
//  lcd.write(byte(0));
  lcd.setCursor(0, 1);
  lcd.print("Very-very-very loooong texttttt");
  //lcd.print("<------Eto ty!)");
}

void loop() {
  for (int i = 0; i < 5; i++) {
    lcd.scrollDisplayLeft();
    delay(1050);
  }
 // Turn off the blinking cursor:
//  lcd.noBlink();
//  delay(3000);
//  // Turn on the blinking cursor:
//  lcd.blink();
//  delay(3000);
}
