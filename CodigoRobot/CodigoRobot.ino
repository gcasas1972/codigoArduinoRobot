
// Definición de pines para los motores
const int M1_A = 13;
const int M1_B = 12;
const int M2_A = 11;
const int M2_B = 10;

char comando;

// Configuración inicial
void setup() {

  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);

  // Inicializar comunicación serial
  Serial.begin(9600);

  detener();

  Serial.println("Control de motores iniciado");
  Serial.println("f = Adelante");
  Serial.println("b = Atras");
  Serial.println("r = Derecha");
  Serial.println("l = Izquierda");
}

// Programa principal
void loop() {

  if (Serial.available() > 0) {

    comando = Serial.read();

    switch (comando) {

      case 'f':
        adelante();
        Serial.println("Adelante");
        break;

      case 'b':
        atras();
        Serial.println("Atras");
        break;

      case 'r':
        derecha();
        Serial.println("Derecha");
        break;

      case 'l':
        izquierda();
        Serial.println("Izquierda");
        break;
      case 's':
        detener();
        Serial.println("Motores detenidos");
        break;
      default:
        detener();
        break;
    }
  }
}

// Movimiento hacia adelante
void adelante() {

  digitalWrite(M1_A, HIGH);
  digitalWrite(M1_B, LOW);

  digitalWrite(M2_A, HIGH);
  digitalWrite(M2_B, LOW);
}

// Movimiento hacia atras
void atras() {

  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);

  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, HIGH);
}

// Giro hacia la derecha
void derecha() {

  digitalWrite(M1_A, HIGH);
  digitalWrite(M1_B, LOW);

  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, HIGH);
}

// Giro hacia la izquierda
void izquierda() {

  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, HIGH);

  digitalWrite(M2_A, HIGH);
  digitalWrite(M2_B, LOW);
}

// Detener los motores
void detener() {

  digitalWrite(M1_A, LOW);
  digitalWrite(M1_B, LOW);

  digitalWrite(M2_A, LOW);
  digitalWrite(M2_B, LOW);
}
