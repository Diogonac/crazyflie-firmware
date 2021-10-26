#include "mbed.h"
#include "crazyflie.h"

// Declaro o mixer
Mixer mixer;


// Main program
int main(){

// Arm mixer
mixer.arm();

// Actuate motor with 70% mg total thrust force (N) and zero torques
mixer.actuate (0.0,0.005,0,0);
wait(5);

// Disarm mixer 
mixer.disarm();

//End of program

    while (true) {
    }

}