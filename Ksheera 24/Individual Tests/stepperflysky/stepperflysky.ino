// Arduino Pins for stepper control
const int stepPin = 2;
const int dirPin = 3;

// RC Receiver Input Pins
const int chXPin = 7;  // Joystick X-axis (left/right)
const int chYPin = 8;  // Joystick Y-axis (up/down)

int chXValue;
int chYValue;

void setup() {
  // Setup Serial Monitor for debugging
  Serial.begin(9600);

  // Setup pin modes for Stepper Driver
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // RC Receiver Pins as inputs
  pinMode(chXPin, INPUT);
  pinMode(chYPin, INPUT);
}

void loop() {
  // Read PWM signal from FlySky receiver (1000 to 2000 microseconds)
  chXValue = pulseIn(chXPin, HIGH, 25000);
  chYValue = pulseIn(chYPin, HIGH, 25000);

  // Debugging: Check receiver input values
  Serial.print("X: "); Serial.print(chXValue);
  Serial.print(" | Y: "); Serial.println(chYValue);

  // Control thresholds (tune as necessary)
  if (chYValue > 1600) {
    // Move motor forward (e.g., upward)
    digitalWrite(dirPin, HIGH);
    stepMotor(200); // Adjust steps for desired movement
  } 
  else if (chYValue < 1400) {
    // Move motor backward (e.g., downward)
    digitalWrite(dirPin, LOW);
    stepMotor(200);
  }

  // Add delay to avoid overly sensitive controls
  delay(20);
}

// Function to generate steps
void stepMotor(int steps) {
  for(int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500); // Pulse duration (adjust for speed)
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}
