#define LED1_PIN 9  
#define LED2_PIN 10 

void setup() {
  pinMode(LED1_PIN, OUTPUT); 
  pinMode(LED2_PIN, OUTPUT);  
}

void loop() {

  digitalWrite(LED1_PIN, HIGH); 
  delay(500);  
  digitalWrite(LED1_PIN, LOW);  
  delay(500);  

  digitalWrite(LED2_PIN, HIGH);  
  delay(700);  
  digitalWrite(LED2_PIN, LOW);   
  delay(700);  
}

