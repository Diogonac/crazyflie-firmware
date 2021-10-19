#include "attitude_estimator.h"

// Class Constructor
AttitudeEstimator :: AttitudeEstimator () : imu(IMU_SDA ,IMU_SCL){

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
void AttitudeEstimator ::init(){

imu.init();

}

// Estimate Euler angles (rad) and angular velocities (rad/s)
void AttitudeEstimator :: estimate (){

    imu.read();

    ax = imu.ax;
    ay = imu.ay;
    az = imu.az;

    phi_a = atan2(-ay, -az); 

    phi = phi_a;





}
