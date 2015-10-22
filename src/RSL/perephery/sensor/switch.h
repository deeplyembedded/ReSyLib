/*
 * switch.h
 *
 *      @date 22.10.2015
 *      @author Easy, JI
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "../sensor.h"

class Switch: public Sensor {

private:

    /**
     * remembers if the switch is single or double poled.
     */
    bool doublePole;
    
    /**
     * remembers the active state of the switch (true = HIGH).
     */
    bool activeState;
    
    /**
     * the first (or only) gpio pin used by the switch.
     */
    GPIOPIN pin1;
    
    /**
     * the second gpio pin used by the switch.
     */
    GPIOPIN pin2;

public:

    /**
     * constructor for single poled switches.
     * registers the GPIOPIN.
     * @param pin1 the PIN used by the switch
     */
    Switch(GPIOPIN pin1);

    /**
     * constructor for double poled switches.
     * registers the GPIOPINs.
     * @param pin1 the main PIN used by the switch
     * @param pin2 the second PIN used by the switch
     */
    Switch(GPIOPIN pin1, GPIOPIN pin2);

    /**
     * deconstructor that unregisters the GPIOPINs
     */
    virtual ~Switch();
    
    /**
     * get the active state of the switch.
     * @return true, if switch is in active state - false otherwise
     */
    bool isPressed();
    
    /**
     * set the active state of the switch to HIGH or LOW.
     * @param state the active gpio state
     */
    void setActiveState(GPIOSTATE state);

private:
    /**
     * copy constructor set to private so Switch can't be called by value.
     */
    Switch(const Switch& b);

    /**
     * set to private so Switch can not get assigned.
     */
    Switch& operator=(Switch& b);
};

#endif /* SWITCH_H_ */
