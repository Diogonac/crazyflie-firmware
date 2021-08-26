#include "mbed.h"
#include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);

// Main program
int main()
{

        wait(2);
        motor = 1.0;
        wait(10);
        motor = 0;
        
    // Turn motor on (20% power) and off every second
    while(true) 
    {
        // motor = 0.1;
        // wait(5);
        // motor = 0.0;
        // wait(0.5);
    }
}
