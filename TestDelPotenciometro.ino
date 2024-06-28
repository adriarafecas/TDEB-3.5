// Definició del pin del potenciòmetre
const int potPin = A22;//pin A22->R3
int lastPotValue = 0;
const int thresholdPercentage = 1; // Percentatge de canvi necessari per mostrar el valor

void setup() {
  // Inicialitza la comunicació sèrie a 9600 baudios
  Serial.begin(9600);

  // Llegeix el valor inicial del potenciòmetre
  lastPotValue = analogRead(potPin);
}

void loop() {
  // Llegeix el valor actual del potenciòmetre
  int currentPotValue = analogRead(potPin);

  // Calcula el percentatge de canvi
  int change = abs(currentPotValue - lastPotValue);
  int changePercentage = (change * 100) / 1023;

  // Comprova si el canvi supera el llindar
  if (changePercentage >= thresholdPercentage) {
    // Mostra el nou valor del potenciòmetre
    Serial.print("Valor del potenciòmetre: ");
    Serial.println(currentPotValue);

    // Actualitza l'últim valor conegut del potenciòmetre
    lastPotValue = currentPotValue;
  }

  // Petit retard per evitar lectures massa freqüents
  delay(100);
}
