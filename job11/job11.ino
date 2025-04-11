const int buttonPin = 4;
const int ledPin = 8;
const int fanPin = 9;

bool ledOn = false;
bool fanOn = false;
bool buttonPressed = false;

unsigned long ledStartTime = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
}

void loop() {

  if (digitalRead(buttonPin) == LOW && !buttonPressed) {
    buttonPressed = true;
    delay(50); // 

    if (!ledOn && !fanOn) {

      digitalWrite(ledPin, HIGH);
      ledStartTime = millis();
      ledOn = true;
    } else if (fanOn) {

      digitalWrite(fanPin, LOW);
      fanOn = false;
    }
  }


  if (digitalRead(buttonPin) == HIGH && buttonPressed) {
    buttonPressed = false;
    delay(50);
  }


  if (ledOn && millis() - ledStartTime >= 15000) {
    digitalWrite(ledPin, LOW);  
    digitalWrite(fanPin, HIGH); 
    ledOn = false;
    fanOn = true;
  }
}
