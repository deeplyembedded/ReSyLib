/*
 * servo.cpp
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */
 
#include "servo.h"
 
Servo::Servo(GPIOPin servoPin){
    currentPosition = 0;
    
    servoPin = createGPIOResource(GPIOType.PWM, servoPin);
    servoPin.setPeriod(20000000); // todo set period to 20ms

    // todo pass enum as parameter
    // create and register new pwm pin
    // configure pin for pwm use
}

Servo::~Servo(){ 
    // todo use interfaces for unregister servo 
    // todo release pin stuff (set to default settings)
}

double Servo::getPosition(void) {
    return currentPosition;
}

void Servo::setPosition(double position) {
    currentPosition = position;
    
    // todo check for min max value
    servoPin.setDuty(1000000 + (1000000*position));

    // todo calculate from degrees to pwm value_comp
    // todo use pwm hal to set values
}

