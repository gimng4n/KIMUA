/*
Once Upon An Arduino - Indiana Jones
TEAM: KIMIA
MEMBERS: Kim Ngan Nguyen & Tamia Hoyt
AET 313
*/

//  Assign pin number to buttons
const int buttonOne = 10;
const int buttonTwo = 8;
const int buttonThree = 6;
const int buttonFour = 5;

//  Assign pin number to LEDs
const int redPin = 12;
const int redPin2 = 13;

//  Static State Change Detections
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int previousButtonState = 0;
int previousButtonState2 = 0;
int previousButtonState3 = 0;
int previousButtonState4 = 0;

//  Adding in all four servos
#include <Servo.h>
Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;

void setup() {
  //  Assign pin number to each servo
  servoOne.attach(11);
  servoTwo.attach(9);
  servoThree.attach(7);
  servoFour.attach(4);

  // reset all servos
  servoOne.write(140); 
  servoTwo.write(150);  
  servoThree.write(10);
  servoFour.write(90);

  // set all buttons as INPUTs
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
  pinMode(buttonThree, INPUT);
  pinMode(buttonFour, INPUT);

  // set LEDs as OUTPUTS and reset all LEDs
  pinMode(redPin, OUTPUT);
  pinMode(redPin2, OUTPUT);
  digitalWrite(redPin2, LOW);
  digitalWrite(redPin, LOW);

  Serial.begin(9600);
}

void loop() {

  //  Store current state of each button
  buttonState1 = digitalRead(buttonOne);
  buttonState2 = digitalRead(buttonTwo);
  buttonState3 = digitalRead(buttonThree);
  buttonState4 = digitalRead(buttonFour);

  //  First Interaction (1 Servo + 2 LEDs)
  if (buttonState1 != previousButtonState) {
    if (buttonState1 == HIGH) {
      delay(2000);
      digitalWrite(redPin, HIGH);
      digitalWrite(redPin2, HIGH);
      servoOne.write(43);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState = buttonState1;

  // Third Interaction (1 Servo Bridge)
  if (buttonState2 != previousButtonState2) {
    if (buttonState2 == HIGH) {
      servoTwo.write(100);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState2 = buttonState2;

  // Fourth Interaction (1 Servo Axe)
  if (buttonState3 != previousButtonState3) {
    if (buttonState3 == HIGH) {
      delay(2000);
      for (int i = 0; i <= 3; i++) { //action
        servoThree.write(110);
        delay(500);
        servoThree.write(10);
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
      servoFour.write(0);
      Serial.println("button pressed");
    } else {
      Serial.println("button released");
    }
  }
  previousButtonState4 = buttonState4;
}
