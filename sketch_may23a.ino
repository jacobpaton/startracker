// Define pin connections & motor's steps per revolution
const int resetPosPin = 2;
const int onOffPin = 3;
const int ms1Pin = 11;
const int ms2Pin = 10;
const int ms3Pin = 9;
const int enablePin = 8;
const int dirPin = 7;
const int stepPin = 6;
const int stepsPerRevolution = 525;
const bool start = false;
int stepsTaken = 0;
int dir = LOW;
int delayTime = 525;

void setup() {
  // Set up serial
  Serial.begin(9600);

  // Declare pins as inputs from buttons
  pinMode(resetPosPin, INPUT_PULLUP);
  pinMode(onOffPin, INPUT_PULLUP);
  
  // Declare pins as outputs to driver
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}

//void resetPos() {
//  Serial.print("Resetting position\n");
//  digitalWrite(dirPin, LOW);
//  
//  while (stepsTaken) {
//    digitalWrite(stepPin, HIGH);
//    digitalWrite(stepPin, LOW);
//    stepsTaken--;
//    delay(100);
//  }
//
//  digitalWrite(dirPin, HIGH);
//}

void switchDir() {
  Serial.print("=======================================\n");
  Serial.print("Switch Direction\n");
  Serial.print("=======================================\n");
  if (dir == HIGH) {
    dir = LOW;
    delayTime = 1;
  } else {
    dir = HIGH;
    delayTime = 525;
  }
  digitalWrite(dirPin, dir);
  delay(525xqx);
}

void turnOff() {
  digitalWrite(enablePin, HIGH);
  Serial.print("=======================================\n");
  Serial.print("Off\n");
  Serial.print("=======================================\n");
  // Wait to turn on
  while (digitalRead(onOffPin) == LOW) {}
  Serial.print("=======================================\n");
  Serial.print("On\n");
  Serial.print("=======================================\n");
  digitalWrite(enablePin, LOW);
}

void loop() {
    // Set motor direction clockwise
    digitalWrite(dirPin, dir);
    
    // Spin motor one revolution
    for (int i=0; i < stepsPerRevolution; i++)
    {
      // Do step
      Serial.print("Step\n");
      digitalWrite(stepPin, HIGH);
      digitalWrite(stepPin, LOW);
      stepsTaken++;

      // Check reset button
//      if (digitalRead(resetPosPin) == LOW) {
//        switchDir();
//      }

      // Check on/off
      if (digitalRead(onOffPin) == LOW) {
        turnOff();
      }
      
      // Wait
      delay(delayTime);
    }
}
