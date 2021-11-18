#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

// Attitude estimator Class
class AttitudeEstimator {

public:
  // Class contructor
  AttitudeEstimator();

  // Initialize class
  void init();

  // Estimate Euler angles (rad) and angular velocities (rad/s)
  void estimate();

  // Euler angles (rad)
  float phi , theta , psi;

  // Angular velocities (rad/s)
  float p, q, r;

private:
  // IMU sensor object
  BMI088 imu;

  // IMU variabes
  float ax, ay, az;

  // Variables for calc phi and theta from acc
  float phi_a, theta_a;

// Variables for calc phi and theta from gyr
float phi_g, theta_g, psi_g;

// Variables to calculate bias error
float p_bias, q_bias, r_bias;
float sum_p, sum_q, sum_r;


};

#endif