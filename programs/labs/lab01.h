#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut BLUE(LED_BLUE_L);
DigitalOut RED_L(LED_RED_R);
DigitalOut RED_R(LED_RED_L);
DigitalOut GREEN_L(LED_GREEN_R);
DigitalOut GREEN_R(LED_GREEN_L);

// Define all motors as PWM objects
PwmOut M1(MOTOR1);
PwmOut M2(MOTOR2);
PwmOut M3(MOTOR3);
PwmOut M4(MOTOR4);

Timer tempo_led;
// Main program
int main()
{
    tempo_led.start();
    // Blink blue LED indicating inicialization (5 seconds)
    while(tempo_led.read() < 5){

    BLUE = !BLUE;
    wait_ms(10);

    }
    // Turn on red LEDs indicating motors are armed
    RED_L = 0;
    RED_R = 0;
    
    // Test all motors with different frequencies (to make different noises)
    M1 = 0.1;
    M2 = 0.7;
    M3 = 0.5;
    M4 = 0.7;
    wait(0.5);
    M1 = 0.0;
    M2 = 0.0;
    M3 = 0.0;
    M4 = 0.0;
    wait(0.5);
    
    // Turn off red LEDs indicating motors are disarmed
    RED_L = 1;
    RED_R = 1;
    
    // Blink green LEDs indicating end of program
    GREEN_L = 0;
    GREEN_R = 0;        

    while(true)
    {
        
    }
}
