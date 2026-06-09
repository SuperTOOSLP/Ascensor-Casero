// ===============================
// ASCENSOR CASERO - ARDUINO UNO
// ===============================

// Salidas motor
const int pin_subir = 8;
const int pin_bajar = 9;

// LEDs indicadores
const int led_arriba = 3;
const int led_abajo = 2;

// Sensores de final de carrera
const int sensor_arriba = 6;
const int sensor_abajo = 5;

// Botones
const int boton_subir = 12;
const int boton_bajar = 11;

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

  // Estado inicial (cabina abajo)
  digitalWrite(led_arriba, HIGH);
  digitalWrite(led_abajo, LOW);
}

void loop() {

  // ==========================
  // SENSOR ARRIBA
  // ==========================
  if (digitalRead(sensor_arriba) == LOW) {

    digitalWrite(pin_subir, LOW);   // detener motor

    digitalWrite(led_arriba, LOW);  // encender LED arriba
    digitalWrite(led_abajo, HIGH);  // apagar LED abajo
  }

  // ==========================
  // SENSOR ABAJO
  // ==========================
  if (digitalRead(sensor_abajo) == LOW) {

    digitalWrite(pin_bajar, LOW);   // detener motor

    digitalWrite(led_arriba, HIGH); // apagar LED arriba
    digitalWrite(led_abajo, LOW);   // encender LED abajo
  }

  // ==========================
  // SEGURIDAD
  // ==========================
  if (digitalRead(sensor_arriba) == LOW &&
      digitalRead(sensor_abajo) == LOW) {

    digitalWrite(pin_subir, LOW);
    digitalWrite(pin_bajar, LOW);
  }

  // ==========================
  // BOTÓN SUBIR
  // ==========================
  if (digitalRead(boton_subir) == LOW &&
      digitalRead(boton_bajar) == HIGH &&
      digitalRead(sensor_arriba) == HIGH) {

    digitalWrite(pin_subir, HIGH);
    digitalWrite(pin_bajar, LOW);
  }

  // ==========================
  // BOTÓN BAJAR
  // ==========================
  if (digitalRead(boton_subir) == HIGH &&
      digitalRead(boton_bajar) == LOW &&
      digitalRead(sensor_abajo) == HIGH) {

    digitalWrite(pin_subir, LOW);
    digitalWrite(pin_bajar, HIGH);
  }
}
