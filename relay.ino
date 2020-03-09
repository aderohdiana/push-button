#define relay1 40
#define relay2 42
#define relay3 44
#define relay4 46
#define button 48

int count;

unsigned long interval = 1000; // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(button);
  Serial.println(val);
  delay(10);
  unsigned long currentMillis = millis(); // grab current time
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    if (val == 0) {
      count++;
      delay(300);
      if (count == 1) {
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        delay(5000);
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        delay(5000);
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
      }
      if (count == 2) {
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        count = 0;
      }
    }
  }
}
