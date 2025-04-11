#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

const int buttonPin = 3; 
bool isRunning = false;
bool lastButtonState = HIGH;

int seconde = 0;
int minute = 30;
int heure = 20;

unsigned long previousMillis = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  
  if (buttonState == LOW && lastButtonState == HIGH) {
    isRunning = !isRunning; 
    delay(200);
  }
  lastButtonState = buttonState;


  if (isRunning && millis() - previousMillis >= 1000) {
    previousMillis = millis();
    seconde++;

    if (seconde >= 60) {
      seconde = 0;
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