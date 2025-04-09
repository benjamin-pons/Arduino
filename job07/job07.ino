#define LED_COUNT 8


int ledPins[LED_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {

  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(ledPins[i], HIGH);  
    delay(300); 
    digitalWrite(ledPins[i], LOW);   
    delay(300); 
  }
}
