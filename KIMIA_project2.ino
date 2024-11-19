const int buttonOne = 10;
const int buttonTwo = 8;
const int buttonThree = 6;
const int buttonFour = 5;


const int redPin = 12;
const int redPin2 = 13;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int previousButtonState = 0;
int previousButtonState2 = 0;
int previousButtonState3 = 0;
int previousButtonState4 = 0;

#include <Servo.h>
Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;

void setup() {
  servoOne.attach(11);
  servoTwo.attach(9);
  servoThree.attach(7);
  servoFour.attach(2);

  servoOne.write(110);  // 10 90
  servoTwo.write(56);   // go down
  servoThree.write(50); // 30
  servoFour.write(180);

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
  buttonState3 = digitalRead(buttonThree);
  buttonState4 = digitalRead(buttonFour);

  //  First Interaction (1 Servo + 2 LED)
  if (buttonState1 != previousButtonState) {
    if (buttonState1 == HIGH) {
      digitalWrite(redPin, HIGH);
      digitalWrite(redPin2, HIGH);
      servoOne.write(33);
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


  // Third Interaction (1 Servo Axe)
  if (buttonState3 != previousButtonState3) {
    if (buttonState3 == HIGH) {
      for (int i = 0; i <= 3; i++) { //action
        servoThree.write(180);
        delay(500);
        servoThree.write(110);
        delay(500);
      }
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState3 = buttonState3;

    // Fifth Interaction (1 Servo Boulder)
  if (buttonState4 != previousButtonState4) {
    if (buttonState4 == HIGH) {
      servoFour.write(90);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState4 = buttonState4;
}
