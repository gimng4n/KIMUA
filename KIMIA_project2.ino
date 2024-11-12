// const int redPin = 4;
const int buttonPin = 2;
int buttonState = 0;
int previousButtonState = 0;

 #include <Servo.h>
 Servo myservo;

void setup() {
   myservo.attach(4);
  pinMode(buttonPin, INPUT);
  // pinMode(redPin, OUTPUT);
  Serial.begin(9600);

  // digitalWrite(redPin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
// for loop for ax
for (int i = 0; i <= 4; i++) { //action
myservo.write(0);
delay(500)
myservo.write(180);
delay(500)
}

  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      Serial.println("button pressed");
       myservo.write(90);
    // digitalWrite(redPin, HIGH);
    } else {
      Serial.println("button released");
      // digitalWrite(redPin, LOW);
    myservo.write(0);
    }
  }
  previousButtonState = buttonState;
}
