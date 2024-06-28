// Definició dels LEDs
const int ledPins[] = {19, 18, 17, 16};// pin 19->D1, pin 18->D2, pin 17->D3, pin 16->D4
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
int iLoop = 0;

void setup() {
  // Configura els pins dels LEDs com a sortides
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    
    // Encén cada LED inicialment
    digitalWrite(ledPins[i], HIGH);
  }
}

void loop() {
  // Incrementa el valor de iLoop de manera cíclica
  iLoop = (iLoop + 1) % numLeds;

  // Apaga el LED corresponent
  digitalWrite(ledPins[iLoop], LOW);

  // Espera mig segon
  delay(500);

  // Encén el LED corresponent
  digitalWrite(ledPins[iLoop], HIGH);
}
