#include "crazyflie.h"
#include "mbed.h"

// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);

float valor_pwm;

float valor_rpm;

// Funções
float control_motor(float omega_r);

// Main program
int main() {

  motor.period(1.0 / 500.0); // Define a frequência do motor = 500Hz

  valor_pwm = 0.0;

  valor_rpm = 5000.0;

  // Turn motor on (20% power) and off every second
  while (true) {

    motor = control_motor(valor_rpm * pi / 30);
    wait(5);
    motor = 0;
    wait(5);
  }
}

float control_motor(float omega_r) {

  valor_pwm = pow(omega_r, 2.0) * 1.16e-07 + 4.488e-12 * omega_r;

  return valor_pwm;
}