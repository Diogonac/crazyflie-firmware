#include "attitude_estimator.h"

// Class Constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {

  // Initial conditions angles (rad)
  phi = 0.0;
  theta = 0.0;
  psi = 0.0;

  // Initial conditions angular velocities (rad/s)
  p = 0.0;
  q = 0.0;
  r = 0.0;

}

// Initialize class
void AttitudeEstimator ::init() {

  imu.init();

  sum_p = 0.0;
  sum_q = 0.0;
  sum_r = 0.0;

  for (int i = 0; i < 1000; i++) {

    imu.read();

    sum_p += imu.gx;
    sum_q += imu.gy;
    sum_r += imu.gz;

    wait(dt);
  }

  p_bias = sum_p / 1000;
  q_bias = sum_q / 1000;
  r_bias = sum_r / 1000;    

}

// Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimator ::estimate() {

  // Read IMU acc and gyr
  imu.read();

  // Save acc and gyr
  ax = imu.ax;
  ay = imu.ay;
  az = imu.az;

  p = imu.gx - p_bias;
  q = imu.gy - q_bias;
  r = imu.gz - r_bias;

  // Calculate  phi and theta angle from acc
  phi_a = atan2(-ay, -az);
  theta_a = atan2(ax, -((az > 0) - (az < 0)) * sqrt(ay * ay + az * az));

  // No linear solution
  phi_g = phi + (p + sin(phi) * tan(theta) * q + cos(phi) * tan(theta) * r) * dt;
  theta_g = theta + (cos(phi) * q - sin(phi) * r) * dt;
  psi_g = psi + (sin(phi) * (1 / cos(theta)) * q + cos(phi) * (1 / cos(theta)) * r) * dt;

  // Estimate angles with complementare filter (LPF + HPF)
  phi = (1 - alpha) * phi_g + alpha * phi_a; 
  theta = (1 - alpha) * theta_g + alpha * theta_a; 
  psi = psi_g;

}
