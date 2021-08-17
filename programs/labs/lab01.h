#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalInOut BLUE(LED_BLUE_L);
DigitalInOut RED_L(LED_RED_L);
DigitalInOut RED_R(LED_RED_R);


// Define all motors as PWM objects

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    BLUE = 1;
    wait(1);
    BLUE = 0;
    wait(1);
    BLUE = 1;
    wait(1);
    BLUE = 0;
    wait(1);
    BLUE = 1;
    wait(1);

    // Turn on red LEDs indicating motors are armed
    
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    while(true)
    {
        
    }
}
