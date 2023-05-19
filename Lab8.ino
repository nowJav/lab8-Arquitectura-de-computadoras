// encendido y apagado de led con muestra en el monitor serial
/*int rele = 8;

void setup() {
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(rele, HIGH);
  Serial.println("Relé apagado");
  delay(2000); 
  
  digitalWrite(rele, LOW);
  Serial.println("Relé encendido");
  delay(5000); 
}*/
// encendido y apagado controlado desde el monitor serial
int rele = 8;

void setup() {
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case '1':
      digitalWrite(rele, HIGH);
      Serial.println("Relé apagado");
      break;
    case '0':
      digitalWrite(rele, LOW);
      Serial.println("Relé encendido");
      break;
    default:
      Serial.println("Comando no reconocido");
      break;
  }
}


