// Definició dels pins del driver de motor
const int PWM_B = 23;
const int PWM_A = 20;
const int int_B = 22;
const int int_A = 21;
const int STBY = 1;
int iLoop = 0; // Loop de 0-255 o 0-255
int increaseTheIncrement = 1; // Quantitat que puja
int incrementLoop = increaseTheIncrement; // Saber si puja o baixa

void setup() {
  // Inicialitza la comunicació sèrie a 9600 baudios
  Serial.begin(9600);

  // Configura els pins de PWM com a sortida
  pinMode(PWM_B, OUTPUT);
  pinMode(PWM_A, OUTPUT);
  
  // Configura els pins de direcció com a sortida
  pinMode(int_B, OUTPUT);
  pinMode(int_A, OUTPUT);
  
  // Configura el pin de STBY com a sortida
  pinMode(STBY, OUTPUT);

  // Activa el driver del motor (STBY en HIGH)
  digitalWrite(STBY, HIGH);

  // Inicialitza els motors aturats
  analogWrite(PWM_A, 0);
  analogWrite(PWM_B, 0);
  digitalWrite(int_A, HIGH); // Direcció cap endavant per motor A
  digitalWrite(int_B, HIGH); // Direcció cap endavant per motor B
}

void loop() {

  iLoop += incrementLoop;

  // Comprova si s'ha arribat al límit superior o inferior i canvia la direcció
  if (iLoop >= 255) {
    incrementLoop = -increaseTheIncrement; // Comença a baixar
    // Canvia la direcció dels motors
    digitalWrite(int_A, !digitalRead(int_A));
    digitalWrite(int_B, !digitalRead(int_B));
  }   
  if (iLoop <= 0) {
    incrementLoop = increaseTheIncrement; // Comença a pujar
    // Canvia la direcció dels motors
    digitalWrite(int_A, !digitalRead(int_A));
    digitalWrite(int_B, !digitalRead(int_B));
  }

  delay(10); // Petit retard per veure el canvi gradual

  // Motor A augmenta o disminueix la velocitat
  analogWrite(PWM_A, iLoop);

  // Motor B augmenta o disminueix la velocitat de manera inversa
  analogWrite(PWM_B, 255 - iLoop);
}
