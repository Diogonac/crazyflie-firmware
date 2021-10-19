#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "crazyflie.h"
#include "mbed.h"

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

  // Variables for calc
  float phi_a, theta_a;


};

#endif