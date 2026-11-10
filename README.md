# Human Following Robot 🤖

## Project Overview
The Human Following Robot is an Arduino-based robotics project that automatically detects and follows a human using ultrasonic and IR sensors.

## Hardware Components
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- L293D Motor Driver Shield
- 2 IR Sensors
- Servo Motor
- 4 DC Geared Motors
- 7.4V–9V Battery
  ## Circuit Diagram

![Human Following Robot Circuit](ARDUINO%20HUMAN%20FOLLOWING%20CAR1.jpg)

## Technologies Used
- Arduino IDE
- Embedded C/C++
- Ultrasonic Sensing
- Infrared Sensing
- Robotics
## Pin Configuration

| Component | Arduino UNO Pin |
|---|---|
| Ultrasonic Trigger | A1 |
| Ultrasonic Echo | A0 |
| Right IR Sensor | A2 |
| Left IR Sensor | A3 |
| Servo Motor Signal | D10 |
| Motor 1 | Motor Shield M1 |
| Motor 2 | Motor Shield M2 |
| Motor 3 | Motor Shield M3 |
| Motor 4 | Motor Shield M4 |

## Software Requirements

- Arduino IDE
- NewPing Library
- Servo Library
- AFMotor Library

## How to Run the Project

1. Install Arduino IDE on your computer.
2. Connect Arduino UNO to your computer using a USB cable.
3. Install the required libraries.
4. Open `Human_Following_Robot.ino`.
5. Select Arduino UNO from Tools → Board.
6. Select the correct COM port.
7. Click Upload.
8. Connect the battery and test the robot.

## Future Improvements

- Improve human/object tracking accuracy.
- Add adjustable following distance.
- Improve obstacle detection.
- Add Bluetooth or wireless monitoring.
## Working Principle
The Human Following Robot works using an HC-SR04 ultrasonic sensor, two IR sensors, a servo motor, and four DC motors.

1. The HC-SR04 ultrasonic sensor measures the distance of an object in front of the robot.
2. The servo motor helps position the ultrasonic sensor for scanning.
3. The two IR sensors detect objects or obstacles on the left and right sides.
4. Arduino UNO processes the sensor readings.
5. The motor driver shield controls the four DC motors according to the sensor inputs.
6. The robot moves forward, turns, or stops based on the programmed conditions.

## Applications
- Human-following assistance robots
- Smart robotics
- Automated transportation systems

## Author
Rajeev Kumar
## Project Images

### Human Following Robot

![Human Following Robot](robot.jpg)
