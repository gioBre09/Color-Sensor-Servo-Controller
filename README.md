# Color-Sensor-Servo-Controller
Color Sensor Servo Controller

This Arduino project controls four servos based on color detection from four color sensors. Each sensor monitors for a specific color, and when detected, the corresponding servo moves down for less than a second and then returns to its initial position.

Features

Integrates with up to four Adafruit TCS34725 color sensors.

Moves a servo motor in response to specific color detection.

Customizable sensor-to-servo mappings and color detection logic.

Hardware Requirements

1 Arduino-compatible microcontroller (e.g., Arduino Uno)

4 Adafruit TCS34725 color sensors

4 Servo motors

Jumper wires and a breadboard

External power source for servos (if required)

Wiring Instructions

Connect Color Sensors: Connect the TCS34725 sensors to the I2C pins of the Arduino:

SDA to A4 (on Arduino Uno)

SCL to A5 (on Arduino Uno)

GND to GND

VIN to 5V

Connect Servos: Attach the servos to digital pins (default: 3, 5, 6, 9). Provide external power if the servos require it.

Power Supply: Ensure the Arduino and servos are powered adequately.

Software Requirements

Arduino IDE

Adafruit TCS34725 library

Servo library (included by default in the Arduino IDE)

Setup

Clone this repository:

git clone https://github.com/your-username/color-sensor-servo-controller.git

Open the color_sensor_servo_controller.ino file in the Arduino IDE.

Install the Adafruit TCS34725 library:

Go to Tools > Manage Libraries.

Search for Adafruit TCS34725 and click Install.

Upload the code to your Arduino.

Code Overview

The code initializes four TCS34725 sensors and four servo motors. It continuously checks each sensor for a specific color. If the defined color is detected, the corresponding servo moves down for a brief moment and returns to its initial position.

Color Detection Logic

The function isColorDetected() determines if a color is detected based on RGB values. By default, it identifies a predominant red color. You can modify this logic as needed:

bool isColorDetected(uint16_t r, uint16_t g, uint16_t b) {
  return (r > g * 1.5 && r > b * 1.5);
}

Servo Movement

When a color is detected, the corresponding servo is triggered:

void moveServo(Servo &servo) {
  servo.write(servoDown);
  delay(900); // Movement duration
  servo.write(servoUp);
}

Customization

Adjust the servo pins by modifying these lines:

const int servoPin1 = 3;
const int servoPin2 = 5;
const int servoPin3 = 6;
const int servoPin4 = 9;

Update the isColorDetected() function to detect other colors.

Troubleshooting

Sensors not detected: Ensure all I2C connections are secure.

Servos not moving: Check the power supply and ensure the pins match those in the code.

License

This project is licensed under the MIT License. See the LICENSE file for details.

Contributing

Feel free to fork this repository and submit pull requests for improvements or bug fixes.

