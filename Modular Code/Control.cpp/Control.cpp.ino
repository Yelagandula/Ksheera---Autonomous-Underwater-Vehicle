#include "Control.h"
#include "Sensors.h"
#include <AccelStepper.h>
#include <PID_v1.h>

#define DIR_PIN 8
#define STEP_PIN 9
#define ENABLE_PIN 10

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

// PID
double Setpoint = 1.5;  // Target depth (m)
double Input;
double Output;
double Kp = 300, Ki = 10, Kd = 50;
PID depthPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void initControl() {
  pinMode(ENABLE_PIN, OUTPUT);
  digitalWrite(ENABLE_PIN, LOW);
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);

  depthPID.SetMode(AUTOMATIC);
  depthPID.SetOutputLimits(-800, 800);
}

void handleDepthControl() {
  Input = currentDepth;
  depthPID.Compute();
  stepper.moveTo(Output);
  stepper.run();
}
