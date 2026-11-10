#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>

// Pin Define
#define RIGHT A2
#define LEFT  A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0.

#define MAX_DISTANCE 250

unsigned int distance = 0;
unsigned int Right_Value = 0;
unsigned int Left_Value = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Motors
AF_DCMotor Motor1(1, MOTOR12_1KHZ);
AF_DCMotor Motor2(2, MOTOR12_1KHZ);
AF_DCMotor Motor3(3, MOTOR34_1KHZ);
AF_DCMotor Motor4(4, MOTOR34_1KHZ);

Servo myservo;
int pos = 0;

void setup() {

  Serial.begin(9600);
  myservo.attach(10);

  // Servo sweep (only once)
  for (pos = 90; pos <= 180; pos++) { myservo.write(pos); delay(10); }
  for (pos = 180; pos >= 0; pos--) { myservo.write(pos); delay(10); }
  for (pos = 0; pos <= 90; pos++) { myservo.write(pos); delay(10); }

  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
}

void loop() {

  distance = sonar.ping_cm();
  if (distance == 0) distance = 250; // No object detected

  Serial.print("Distance: ");
  Serial.println(distance);

  // Read IR sensor values (analog)
  int Right_IR = analogRead(RIGHT);
  int Left_IR  = analogRead(LEFT);

  // Convert to digital-like values
  Right_Value = (Right_IR < 300) ? 0 : 1;
  Left_Value  = (Left_IR  < 300) ? 0 : 1;

  Serial.print("Right = "); Serial.println(Right_Value);
  Serial.print("Left = "); Serial.println(Left_Value);

  // --------------------------
  // FOLLOWING LOGIC
  // --------------------------

  if (distance < 40 && distance > 5) {

    // Forward
    Motor1.setSpeed(200);
    Motor1.run(FORWARD);
    Motor2.setSpeed(200);
    Motor2.run(FORWARD);
    Motor3.setSpeed(200);
    Motor3.run(FORWARD);
    Motor4.setSpeed(200);
    Motor4.run(FORWARD);

  } 
  else if (Right_Value == 0 && Left_Value == 1) {

    // Turn Left
    Motor1.run(FORWARD);
    Motor2.run(FORWARD);
    Motor3.run(BACKWARD);
    Motor4.run(BACKWARD);

  } 
  else if (Right_Value == 1 && Left_Value == 0) {

    // Turn Right
    Motor1.run(BACKWARD);
    Motor2.run(BACKWARD);
    Motor3.run(FORWARD);
    Motor4.run(FORWARD);

  } 
  else {

    // Stop
    Motor1.run(RELEASE);
    Motor2.run(RELEASE);
    Motor3.run(RELEASE);
    Motor4.run(RELEASE);
  }

  delay(100);
}
