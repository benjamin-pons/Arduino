const int bouton = 2;
const int led = 13;

unsigned long dernierAppui = 0;
unsigned long dernierClignotement = 0;
unsigned long debutAppui = 0;

bool etatLED = false;
bool clignoter = false;

int nbAppuis = 0;
bool boutonPrecedent = LOW;
bool appuiLong = false;

void setup() {
  pinMode(bouton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  bool etatBouton = digitalRead(bouton);
  unsigned long maintenant = millis();


  if (etatBouton == HIGH && boutonPrecedent == LOW) {
    debutAppui = maintenant;
    appuiLong = false;
  }

  if (etatBouton == HIGH && (maintenant - debutAppui > 1000) && !appuiLong) {
    etatLED = false;
    clignoter = false;
    digitalWrite(led, LOW);
    nbAppuis = 0;
    appuiLong = true;
  }

  if (etatBouton == LOW && boutonPrecedent == HIGH && !appuiLong) {
    nbAppuis++;
    dernierAppui = maintenant;
  }


  if (nbAppuis > 0 && (maintenant - dernierAppui > 500)) {
    switch (nbAppuis) {
      case 1:
        etatLED = true;
        clignoter = false;
        digitalWrite(led, HIGH);
        break;
      case 2:
        etatLED = true;
        clignoter = false;
        digitalWrite(led, HIGH);
        break;
      case 3:
        clignoter = true;
        break;
    }
    nbAppuis = 0; 
  }

  if (clignoter && (maintenant - dernierClignotement > 500)) {
    etatLED = !etatLED;
    digitalWrite(led, etatLED);
    dernierClignotement = maintenant;
  }

  boutonPrecedent = etatBouton;
}
