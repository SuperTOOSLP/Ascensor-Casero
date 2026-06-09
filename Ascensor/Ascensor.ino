// ===============================
// ASCENSOR CASERO - ARDUINO UNO
// ===============================

// Salidas motor
const int pin_subir = 8;
const int pin_bajar = 9;

// LEDs indicadores
const int led_arriba = 10;
const int led_abajo = 11;

// Sensores de final de carrera
const int sensor_arriba = 2;   // INT0
const int sensor_abajo = 3;    // INT1

// Botones
const int boton_subir = 4;
const int boton_bajar = 5;

void setup() {

  pinMode(pin_subir, OUTPUT);
  pinMode(pin_bajar, OUTPUT);

  pinMode(led_arriba, OUTPUT);
  pinMode(led_abajo, OUTPUT);

  pinMode(sensor_arriba, INPUT_PULLUP);
  pinMode(sensor_abajo, INPUT_PULLUP);

  pinMode(boton_subir, INPUT_PULLUP);
  pinMode(boton_bajar, INPUT_PULLUP);

  // Motor apagado al iniciar
  digitalWrite(pin_subir, LOW);
  digitalWrite(pin_bajar, LOW);

  // Estado inicial
  digitalWrite(led_arriba, HIGH);
  digitalWrite(led_abajo, LOW);

  // Interrupciones
  attachInterrupt(
    digitalPinToInterrupt(sensor_arriba),
    ISR_sensor_arriba,
    LOW
  );

  attachInterrupt(
    digitalPinToInterrupt(sensor_abajo),
    ISR_sensor_abajo,
    LOW
  );
}

void loop() {

  // Seguridad:
  // Si ambos sensores están activos,
  // detener motor
  if (digitalRead(sensor_arriba) == LOW &&
      digitalRead(sensor_abajo) == LOW) {

    digitalWrite(pin_subir, LOW);
    digitalWrite(pin_bajar, LOW);
  }

  // Subir
  if (digitalRead(boton_subir) == LOW &&
      digitalRead(boton_bajar) == HIGH) {

    digitalWrite(pin_subir, HIGH);
    digitalWrite(pin_bajar, LOW);
  }

  // Bajar
  if (digitalRead(boton_subir) == HIGH &&
      digitalRead(boton_bajar) == LOW) {

    digitalWrite(pin_subir, LOW);
    digitalWrite(pin_bajar, HIGH);
  }
}

// ===============================
// INTERRUPCIÓN SENSOR ARRIBA
// ===============================
void ISR_sensor_arriba() {

  digitalWrite(pin_subir, LOW);   // detener

  digitalWrite(led_arriba, LOW);  // encender
  digitalWrite(led_abajo, HIGH);  // apagar
}

// ===============================
// INTERRUPCIÓN SENSOR ABAJO
// ===============================
void ISR_sensor_abajo() {

  digitalWrite(pin_bajar, LOW);   // detener

  digitalWrite(led_arriba, HIGH); // apagar
  digitalWrite(led_abajo, LOW);   // encender
}