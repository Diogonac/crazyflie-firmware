#ifndef horizontal_estimator_h
#define horizontal_estimator_h

#include "crazyflie.h"
#include "mbed.h"

// Horizontal estimator Class
class HorizontalEstimator {

public:
  // Class contructor
  HorizontalEstimator();

  // Initialize class
  void init();

  // Predict horizontal positions and velocities from model
  void predict(float phi , float theta);

  // Correct horizontal velocities with measurements
  void correct(float phi , float theta , float p, float q, float z);

  // Horizontal positions (m) and velocities (m/s) estimations
  float x, y, u, v;


private:

  // Flow sensor object
  PMW3901 flow;

  // Auxiliar variables
  float d, den, u_m, v_m;
  
};

#endif