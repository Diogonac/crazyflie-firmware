#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m
const float Kd = 1.771e-10; // N.m.s^2
const float Kl = 1.472e-8; // N.s^2

// Iterruption time
const float dt = 0.002;

// LPF phi constants
const float wc_phi = 5.0;
const float alpha = (wc_phi * dt) / (1 + wc_phi * dt);

// Attitude controller gains
const float kd_att = 20.0; 
const float kp_att = 135.1580; 






#endif