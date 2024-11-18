const int buttonOne = 10;
const int buttonTwo = 8;

const int redPin = 12;
const int redPin2 = 13;

int buttonState1 = 0;
int buttonState2 = 0;
int previousButtonState = 0;
int previousButtonState2 = 0;

#include <Servo.h>
Servo servoOne;
Servo servoTwo;

void setup() {
  servoOne.attach(11);
  servoTwo.attach(9);
  servoOne.write(105);  // 10 90
  servoTwo.write(56);   // go down

  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);

  // LEDs setup + restart
  pinMode(redPin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  digitalWrite(redPin2, LOW);
  digitalWrite(redPin, LOW);

  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonOne);
  buttonState2 = digitalRead(buttonTwo);

  //  First Interaction (1 Servo + 2 LED)
  if (buttonState1 != previousButtonState) {
    if (buttonState1 == HIGH) {
      digitalWrite(redPin, HIGH);
      digitalWrite(redPin2, HIGH);
      servoOne.write(30);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState = buttonState1;

  // Third Interaction (1 Servo Bridge)
  if (buttonState2 != previousButtonState2) {
    if (buttonState2 == HIGH) {
      servoTwo.write(0);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState2 = buttonState2;
}
