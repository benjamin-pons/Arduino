#define LED_ROUGE 1
void setup() {
  pinMode(LED_ROUGE, OUTPUT);  
}

void loop() {
  
  for (int i = 0; i <= 255; i++) {
    analogWrite(LED_ROUGE, i); 
    delay(10);  
  }
}
