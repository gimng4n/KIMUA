const int redPin = 4;
const int buttonPin = 2;
int buttonState = 0;
int previousButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);

  digitalWrite(redPin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      Serial.println("button pressed");
      digitalWrite(redPin, HIGH);
    } else {
      Serial.println("button released");
      digitalWrite(redPin, LOW);
    }
  }
  previousButtonState = buttonState;
}
