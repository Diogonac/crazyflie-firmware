#include "horizontal_estimator.h"

// Class Constructor
HorizontalEstimator::HorizontalEstimator() : flow(PA_7, PA_6, PA_5, PB_4) {

  // Initial conditions
  x = 0.0;
  y = 0.0;
  u = 0.0;
  v = 0.0;

  d = 0.0;
  den = 0.0;
  u_m = 0.0;
  v_m = 0.0;
}

// Initialize class
void HorizontalEstimator ::init() { 
    flow.init(); 
    }

// Predict horizontal positions and velocities from model
void HorizontalEstimator ::predict(float phi, float theta) {

   u = u + g * theta * dt;
   v = v - g * phi * dt;

   x = x + u * dt;
   y = y + v * dt;

}

// Correct horizontal velocities with measurements
void HorizontalEstimator ::correct(float phi, float theta, float p, float q, float z) {

  den = cos(phi) * cos(theta);

  if (den > 0.5) {

    d = z / den;

    flow.read();

    u_m = (sigma * flow.px + q) * d;
    v_m = (sigma * flow.py - p) * d;

    u = u + l_hor * dt * (u_m - u);
    v = v + l_hor * dt * (v_m - v);
  }
}