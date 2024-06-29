const int MAX_CHARACTERS = 36;  // Nombre màxim de caràcters a guardar dels últims missatges
char receivedMessage[MAX_CHARACTERS + 1];  // Array per emmagatzemar els caràcters rebuts
int currentIndex = 0;  // Índex actual a l'array de caràcters

void setup() {
  // Inicialitza la comunicació serial 2 a 9600 baudios
  Serial2.begin(9600);

  // Inicialitza l'array de caràcters amb caràcters espais
  for (int i = 0; i < MAX_CHARACTERS; ++i) {
    receivedMessage[i] = ' ';
  }
  receivedMessage[MAX_CHARACTERS] = '\0'; // Caràcter nul al final de l'array de caràcters
    
  // Espera a que el port serial estigui obert
  while (!Serial2);
}

void loop() {
  // Envia el missatge amb els últims caràcters rebuts
  Serial2.println("******************************************");
  Serial2.println("*  Missatge de prova des de Teensy 3.5   *");
  Serial2.println("*  He rebut:                             *");
  Serial2.print("*  ");
  
  // Imprimeix els últims caràcters rebuts
  for (int i = 0; i < MAX_CHARACTERS; ++i) {
    char aux = receivedMessage[(i + currentIndex) % MAX_CHARACTERS];
    if (aux == '\n') {
      Serial2.print(' ');  // Si és un salt de línia, imprimeix un espai
    } else {
      Serial2.print(aux);
    }
  }
  
  Serial2.println("  *");
  Serial2.println("******************************************");

  // Llegeix les dades del port serial 2 (pins 9 i 10)
  while (Serial2.available()) {
    char c = Serial2.read();

    // Afegir el caràcter al final de l'array i actualitzar l'índex
    receivedMessage[currentIndex] = c;
    currentIndex = (currentIndex + 1) % MAX_CHARACTERS;  // Circular buffer
  }

  // Espera 1 segon si no hi ha dades disponibles per reduir l'activitat del bucle
  if (!Serial2.available()) {
    delay(1350);
  }
}
