const int pin_red_LED = 9;
const int pin_green_LED = 5;
const int pin_LDR = A0;

const unsigned long open_delay = 3000;

void setup() {

  pinMode(pin_red_LED, OUTPUT);
  pinMode(pin_green_LED, OUTPUT);

  Serial.begin(9600);

  digitalWrite(pin_red_LED, HIGH);
  digitalWrite(pin_green_LED, LOW);
  Serial.println("System started. Doors are CLOSED.");
}

void loop() {

  int ldr_value = analogRead(pin_LDR);

  if (ldr_value > 512) {

    digitalWrite(pin_red_LED, LOW);
    digitalWrite(pin_green_LED, HIGH);
    Serial.println("Object detected! Doors are OPENING.");

    delay(open_delay);
    

  } 
  else {

    if (digitalRead(pin_red_LED) == LOW) { 
      digitalWrite(pin_green_LED, LOW);
      digitalWrite(pin_red_LED, HIGH);
      Serial.println("No objects detected. Doors are CLOSED.");
    }
  }
  
  delay(100);
}