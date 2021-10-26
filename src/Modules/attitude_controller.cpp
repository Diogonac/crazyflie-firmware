#include "attitude_controller.h"

// Class Constructor
AttitudeController ::AttitudeController(){

  // Initial conditions toques
  tau_phi = 0.0;
  tau_theta = 0.0;
  tau_psi = 0.0;

}

/* Control torques (N.m) given reference angles (rad) and current angles (rad) and
angular velocities (rad/s) */
void AttitudeController :: control(float phi_r , float theta_r , float psi_r , float phi, float theta , float psi , float p, float q, float r)
 {

  tau_phi = control_siso(phi_r, phi, p, kp_att, kd_att) * I_xx;
  tau_theta = control_siso(theta_r, theta, q, kp_att, kd_att) * I_yy;
  tau_psi = control_siso(psi_r, psi, r, kp_att, kd_att) * I_zz;
 

}


/* Control torque (N.m) given reference angle (rad) and current angle (rad) and
angular velocity (rad/s) with given controller gains */
float AttitudeController :: control_siso(float angle_r , float angle , float rate, float kp , float kd)
{

return kp * (angle_r - angle) + kd * (0 - rate);

}