#include "crazyflie.h"
#include "mbed.h"
#include <cmath>
#include <cstdio>

// Define all motors as PWM output object
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

// Define angular velocities (rad/s)
float omega_1;
float omega_2;
float omega_3;
float omega_4;

// Funções
float control_motor(float omega_r);

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);

// Main program
int main() {

// Set all PWM frequencies to 500Hz
  motor1.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor2.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor3.period(1.0 / 500.0); // Define a frequência do motor = 500Hz
  motor4.period(1.0 / 500.0); // Define a frequência do motor = 500Hz

  // Actuate motor with 70% mg total thrust force (N) and zero torques (N.m)

//actuate (0.6*m*g,0,0,0); // Teste 1
actuate (0,0.0,0.0,0.005); // Teste 2
//actuate (0,0,0.005,0); // Teste 3
//actuate (0,0,0,0.001); // Teste 4
  wait(5);

  // Turn off all motors
  actuate (0,0,0,0);

  // End of program
  while(true){

  }

}

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor(float omega_r) {

  return pow(omega_r, 2.0) * 1.16e-07 + 4.488e-12 * omega_r;
}

// Converts total trust force (N) and torques (N.m) to angular velocities
// (rad/s)
void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {

  omega_1 = f_t / (4 * Kl) - tau_phi / (4 * Kl * l) - tau_theta / (4 * Kl * l) - tau_psi / (4 * Kd);
  omega_2 = f_t / (4 * Kl) - tau_phi / (4 * Kl * l) + tau_theta / (4 * Kl * l) + tau_psi / (4 * Kd);
  omega_3 = f_t / (4 * Kl) + tau_phi / (4 * Kl * l) + tau_theta / (4 * Kl * l) - tau_psi / (4 * Kd);
  omega_4 = f_t / (4 * Kl) + tau_phi / (4 * Kl * l) - tau_theta / (4 * Kl * l) + tau_psi / (4 * Kd);

  if (omega_1 < 0) {
    omega_1 = 0;
  } else {
    omega_1 = sqrt(omega_1);
  }

  if (omega_2 < 0) {
    omega_2 = 0;
  } else {
    omega_2 = sqrt(omega_2);
  }

  if (omega_3 < 0) {
    omega_3 = 0;
  } else {
    omega_3 = sqrt(omega_3);
  }

  if (omega_4 < 0) {
    omega_4 = 0;
  } else {
    omega_4 = sqrt(omega_4);
  }
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
  mixer(f_t, tau_phi, tau_theta, tau_psi);
  motor1 = control_motor(omega_1);
  motor2 = control_motor(omega_2);
  motor3 = control_motor(omega_3);
  motor4 = control_motor(omega_4);
  printf("Motor1= %f, Motor2= %f, Motor3= %f, Motor4= %f \r\n", control_motor(omega_1), control_motor(omega_2), control_motor(omega_3), control_motor(omega_4));
}