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
const float dt_range = 0.05;

// LPF phi constants
const float wc_phi = 0.8;
const float alpha = (wc_phi * dt) / (1 + wc_phi * dt);

// Attitude controller gains phi and theta
const float Ts_att = 0.3;
const float OS_att = 0.5;//0.3;
const float zeta_att = -log(OS_att/100)/sqrt(pow(pi, 2) + pow((log(OS_att/100)), 2));
const float wn_att = 4 / (zeta_att * Ts_att);
const float kd_att = 2 * zeta_att * wn_att;
const float kp_att = pow(wn_att, 2);

// Attitude controller gains psi
const float Ts_att_psi = 0.6;
const float OS_att_psi = 0.5;//0.3;
const float zeta_att_psi = -log(OS_att_psi/100)/sqrt(pow(pi, 2) + pow((log(OS_att_psi/100)), 2));
const float wn_att_psi = 4 / (zeta_att_psi * Ts_att_psi);
const float kd_att_psi = 2 * zeta_att_psi * wn_att_psi;
const float kp_att_psi = pow(wn_att_psi, 2);

// Vertical estimator constants
const float wc = 10; //aprox. 500Hz
const float zeta = sqrt(2)/2;
const float l1 = wc*wc;
const float l2 = 2 * zeta * wc; 

// Vertical controller gains
const float Ts_vert = 3.0;
const float OS_vert = 0.5;//0.2;
const float zeta_vert = -log(OS_vert/100)/sqrt(pow(pi, 2) + pow((log(OS_vert/100)), 2));
const float wn_vert = 4 / (zeta_vert * Ts_vert);

const float kd_vert = 2 * zeta_vert * wn_vert;
const float kp_vert = pow(wn_vert, 2);

// Horizontal estimator constants
const float angle_flow = 42.0 * pi / 180.0;
const float W_pixel = 420.0;
const float sigma = (2 * tan(angle_flow / 2)) / (W_pixel * dt);
const float l_hor = 50.0; 

// Horizontal controller gains
const float Ts_hor = 3.0;
const float OS_hor = 0.5;
const float zeta_hor = -log(OS_hor/100)/sqrt(pow(pi, 2) + pow((log(OS_hor/100)), 2));
const float wn_hor = 4 / (zeta_hor * Ts_hor);

const float kd_hor = 2 * zeta_hor * wn_hor;
const float kp_hor = pow(wn_hor, 2);


#endif