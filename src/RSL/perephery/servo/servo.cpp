/*
 * servo.cpp
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */
 
#include "servo.h"
 
Servo::Servo(GPIOPIN servoPin){ 
    curentPosition = 0;
    
    // todo pass enum as parameter
    // create and register new pwm pin
    // configure pin for pwm use
}

Servo::~Servo(){ 
    // todo use interfaces for unregister servo 
    // todo release pin stuff (set to default settings)
}

uint16_t Servo::getPosition(void) { 
    return currentPosition;
}

void Servo::setPosition(uint16_t degrees) { 
    currentPosition = degrees;
    
    // todo calculate from degrees to pwm value_comp
    // todo use pwm hal to set values
}

