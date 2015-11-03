/*
 * servo.h
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "../periphery.h"

class Servo: public Periphery {

private:

    /**
     * storage of the current position in degrees
     */
    double currentPosition;
    
    /**
     * the pin used for servo pwm
     */
    GPIO_PWM servoPin;

public:

    /**
     * constructor of servo object
     * @param pin used for servo
     */
    Servo(GPIOPin servoPin);

    /**
     * deconstructor of servo object
     */
    virtual ~Servo();
    
    /**
     * get the current servo position
     * @return current servo position
     */
    double getPosition(void);
    
    /**
     * set the servo position in degrees
     * @param desired position in degrees
     */
    void setPosition(double position);

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
