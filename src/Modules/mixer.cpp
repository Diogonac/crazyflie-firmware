#include "mixer.h"

// Class Constructor
Mixer::Mixer()
    : motor1(MOTOR1), motor2(MOTOR2), motor3(MOTOR3), motor4(MOTOR4),
      BLUE(LED_BLUE_L), RED_L(LED_RED_L), RED_R(LED_RED_R),
      GREEN_L(LED_GREEN_L), GREEN_R(LED_GREEN_R) {

  motor1.period(1.0 / 500.0);
  motor2.period(1.0 / 500.0);
  motor3.period(1.0 / 500.0);
  motor4.period(1.0 / 500.0);

  motor1 = 0.0;
  motor2 = 0.0;
  motor3 = 0.0;
  motor4 = 0.0;

  BLUE = 1;
  RED_L = 1;
  RED_R = 1;
  GREEN_L = 0;
  GREEN_R = 0;

  armed = false;

}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {

  mixer(f_t, tau_phi, tau_theta, tau_psi);

  if (armed == true) {

    motor1 = control_motor(omega_r_1);
    motor2 = control_motor(omega_r_1);
    motor3 = control_motor(omega_r_1);
    motor4 = control_motor(omega_r_1);

  } else {

    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
  }
}

// Convert total trust force (N) and torques (N.m) to angular velocities (rad/s)
void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {

  omega_r_1 = f_t / (4 * kl) - tau_phi / (4 * kl * l) -
              tau_theta / (4 * kl * l) - tau_psi / (4 * kd);
  omega_r_2 = f_t / (4 * kl) - tau_phi / (4 * kl * l) +
              tau_theta / (4 * kl * l) + tau_psi / (4 * kd);
  omega_r_3 = f_t / (4 * kl) + tau_phi / (4 * kl * l) +
              tau_theta / (4 * kl * l) - tau_psi / (4 * kd);
  omega_r_4 = f_t / (4 * kl) + tau_phi / (4 * kl * l) -
              tau_theta / (4 * kl * l) + tau_psi / (4 * kd);

  if (omega_r_1 < 0) {
    omega_r_1 = 0;
  } else {
    omega_r_1 = sqrt(omega_r_1);
  }

  if (omega_r_2 < 0) {
    omega_r_2 = 0;
  } else {
    omega_r_2 = sqrt(omega_r_2);
  }

  if (omega_r_3 < 0) {
    omega_r_3 = 0;
  } else {
    omega_r_3 = sqrt(omega_r_3);
  }

  if (omega_r_4 < 0) {
    omega_r_4 = 0;
  } else {
    omega_r_4 = sqrt(omega_r_4);
  }
}

// Convert desired angular velocity (rad/s) to PWM signal (%)
float Mixer::control_motor(float omega_r) {

  return pow(omega_r, 2.0) * 1.16e-07 + 4.488e-12 * omega_r;
}

// Arm all motors
void Mixer::arm() {

  BLUE = 1;
  wait_ms(500);
  BLUE = 0;
  wait_ms(500);

  BLUE = 1;
  wait_ms(500);
  BLUE = 0;
  wait_ms(500);

  BLUE = 1;
  wait_ms(500);
  BLUE = 0;
  wait_ms(500);

  BLUE = 1;
  wait_ms(500);
  BLUE = 0;
  wait_ms(500);

  BLUE = 1;
  wait_ms(500);
  BLUE = 0;
  wait_ms(500);

  armed = true;

  GREEN_L = 1;
  GREEN_R = 1;

  RED_L = 0;
  RED_R = 0;

  wait(2);
}

// Disarm all motors
void Mixer::disarm() {

  GREEN_L = 0;
  GREEN_R = 0;

  RED_L = 1;
  RED_R = 1;

  armed = false;
  actuate(0, 0, 0, 0);
}