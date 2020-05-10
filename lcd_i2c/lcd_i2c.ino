#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Для экрана 20х4 (четырехстрочный)
void setup()
{
lcd.begin();
lcd.setCursor(0, 0); // 1 строка
lcd.print("LCD I2C Test - 20x4");
lcd.setCursor(0, 1); // 2 строка
lcd.print("01234567899876543210");
lcd.setCursor(0, 2); // 3 строка
lcd.print("01234567899876543210");
lcd.setCursor(0, 3); // 4 строка
lcd.print("  geekelectronics.org");
}

void loop()
{

}
