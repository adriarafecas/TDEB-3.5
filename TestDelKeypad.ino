// Definició dels botons
const int teensyButtonPins[] = {14, 39, 38, 37};// pin 14->SW1, pin 39->SW2, pin 38->SW3, pin 37->SW4
const int numButtons = sizeof(teensyButtonPins) / sizeof(teensyButtonPins[0]);
int currentButtonStates[numButtons];
int lastButtonStates[numButtons];

void setup() {
  Serial.begin(9600);

  // Configura els pins dels botons
  for (int i = 0; i < numButtons; i++) {
    // Configura el pin especificat com una entrada amb una resistència pull-up interna habilitada
    pinMode(teensyButtonPins[i], INPUT_PULLUP);

    // Llegeix l'estat inicial del botó
    currentButtonStates[i] = digitalRead(teensyButtonPins[i]);

    // Mostra l'estat inicial dels botons
    Serial.print("Botó ");
    Serial.print(teensyButtonPins[i]);
    Serial.print(": ");
    if (currentButtonStates[i] == LOW) {
      Serial.println("PRESIONAT");
    } else {
      Serial.println("NO PRESIONAT");
    }

    // Actualitza les variables corresponents
    lastButtonStates[i] = currentButtonStates[i];
  }
}

void loop() {
  // Comprova l'estat dels botons
  for (int i = 0; i < numButtons; i++) {
    // Llegeix l'estat actual del botó
    currentButtonStates[i] = digitalRead(teensyButtonPins[i]);

    // Comprova si l'estat ha canviat respecte a l'últim estat conegut
    if (currentButtonStates[i] != lastButtonStates[i]) {
      // Mostra l'estat actual dels botons
      Serial.print("Botó ");
      Serial.print(teensyButtonPins[i]);
      Serial.print(": ");
      if (currentButtonStates[i] == LOW) {
        Serial.println("PRESIONAT");
      } else {
        Serial.println("NO PRESIONAT");
      }

      // Actualitza l'últim estat conegut del botó
      lastButtonStates[i] = currentButtonStates[i];
    }
  }

  // Petit retard per evitar lectures errònies a causa del rebote mecànic dels botons
  delay(50);
}
