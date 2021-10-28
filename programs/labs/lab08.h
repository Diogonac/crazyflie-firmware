#include "crazyflie.h"
#include "mbed.h"


// Define object
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController cont_att;


// Define Ticker objects
Ticker tic;

// Define Interrupt flag and counter variables
bool flag;

// Define Callback functions
void callback() { flag = true; }

// Main program
int main() {
  // Initialize attitude estimator objects
  att_est.init();
  // Initialize interrupt
  tic.attach(&callback, dt);

  // Estimate inicial states
  att_est.estimate();

  // Arm mixer
mixer.arm();

  while (abs(att_est.phi) <= pi / 4.0 && abs(att_est.theta) <= pi / 4.0 && abs(att_est.p) <= 4.0 * pi && abs(att_est.q) <= 4.0 * pi && abs(att_est.r) <= 4.0 * pi) {

    if (flag) {

      flag = false;

      att_est.estimate();

      cont_att.control(0, 0, 0, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);

      // Actuate motor with 70% mg total thrust force (N) and zero torques
      mixer.actuate (0.7*g*m, cont_att.tau_phi, cont_att.tau_theta, cont_att.tau_psi);

    }
  }

mixer.disarm();

}
