#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
int seconde = 0;
int minute = 30;
int heure = 20;

unsigned long previousMillis = 0;
  
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}
void loop() { 
  if (millis() - previousMillis >= 1000) {
    previousMillis = millis();
    seconde++;
    if (seconde == 59) {
      seconde = 0;
      delay(1000);
      minute++;
      if (minute >= 60) {
        minute = 0;
        heure++;
        if (heure >= 24) {
          heure = 0;
        }
      }
    }
    lcd.clear(); 
    lcd.print(heure);
    lcd.print(":");
    lcd.print(minute);
    lcd.print(":");
    lcd.print(seconde);
    delay(500);
    }
  }
