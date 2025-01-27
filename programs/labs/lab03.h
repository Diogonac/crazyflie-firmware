#include "crazyflie.h"
#include "mbed.h"

// Define motor 1 as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

float valor_pwm;

float valor_rpm;

float valor_rad;

// Funções
float control_motor(float omega_r);

// Main program
int main() {

  motor1.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor2.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor3.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor4.period(1.0 / 500.0); // Define a frequência do motor = 500Hz

  valor_pwm = 0.0;

  valor_rpm = 5000.0;
  valor_rad = 2200.0;

  // Turn motor on (20% power) and off every second
  while (true) {

    motor1 = control_motor(valor_rad);
    motor2 = control_motor(valor_rad);
    motor3 = control_motor(valor_rad);
    motor4 = control_motor(valor_rad);

    wait(20);

    motor1 = 0;
    motor2 = 0;
    motor3 = 0;
    motor4 = 0;

    wait(5);
  }
}

float control_motor(float omega_r) {

  valor_pwm = pow(omega_r, 2.0) * 1.16e-07 + 4.488e-12 * omega_r;

  return valor_pwm;
}