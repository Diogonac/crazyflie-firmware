#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

// Mixer Class
class Mixer {

public:
  // Class contructor
  Mixer();

  // Actuate motors with desired total trust force (N) and torques (N.m)
  void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);

  // Arm funtion
  void arm();

  // Disarm function
  void disarm();

  // Bool variables
  bool armed;

private:
  // Motors PWM outputs
  PwmOut motor1, motor2, motor3, motor4;

  // LEDS indicators
  DigitalOut BLUE, RED_L, RED_R, GREEN_L, GREEN_R;

  // Angular velocities (rad/s)
  float omega_r_1, omega_r_2, omega_r_3, omega_r_4;

  // Convert total thrust force (N) and torques (N.m) to angular velocities
  // (rad/s)
  void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);

  // Convert desired angular velocity (rad/s) to PWM signal (%)
  float control_motor(float omega_r);
};

#endif