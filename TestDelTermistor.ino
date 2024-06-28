// Definició del pin del termistor
const int thermistorPin = A21;

void setup() {
  // Inicialitza la comunicació sèrie a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Llegeix el valor actual del termistor
  int currentThermistorValue = analogRead(thermistorPin);

  // Calcula el valor invertit
  int invertedValue = 1023 - currentThermistorValue;

  // Mostra el valor invertit del termistor
  Serial.print("Valor invertit del termistor: ");
  Serial.println(invertedValue);

  // Petit retard per evitar saturar la comunicació sèrie
  delay(500);
}
