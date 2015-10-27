/*
 * servo.h
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "../actor.h"

class Servo: public Actor {

private:

    /**
     * storage of the current position in degrees
     */
    uint16_t currentPosition;
    
    /**
     * the pin used for servo pwm
     */
    GPIOPIN servoPin;

public:

    /**
     * constructor of servo object
     * @param pin used for servo
     */
    Servo(GPIOPIN servoPin);

    /**
     * deconstructor of servo object
     */
    virtual ~Servo();
    
    /**
     * get the current servo position
     * @return current servo position
     */
    uint16_t getPosition(void);
    
    /**
     * set the servo position in degrees
     * @param desired position in degrees
     */
    void setPosition(uint16_t degrees);

private:
    /**
     * hide copy constructor
     */
    Servo(const Servo& b);

    /**
     * hide assignment constructor
     */
    Servo& operator=(Servo& b);
};

#endif /* SERVO_H_ */