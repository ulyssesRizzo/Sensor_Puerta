#define buzzer 6
#define sensor A3

unsigned long tiempoInicio = 0;
const unsigned long retraso = 10000;  // 10 segundos
bool puertaAbierta = false;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int dato = digitalRead(sensor);
  Serial.println(dato);
  delay(1000);

  if (dato == 0) {  // Detecta puerta abierta
    if (!puertaAbierta) {  // Solo marca el tiempo una vez
      puertaAbierta = true;
      tiempoInicio = millis();  // Guarda el tiempo cuando se abrió la puerta
    }
    
    if (millis() - tiempoInicio >= retraso) {  // Verifica si han pasado 10 segundos
      alarma();
    }
  } else {
    puertaAbierta = false;  // Si la puerta está cerrada, resetea la variable
  }
}

void alarma() {
  tone(buzzer, 1000);  // Suena el buzzer
  delay(1000);  // Mantén el buzzer encendido por 1 segundo
  noTone(buzzer);  // Apaga el buzzer
}

