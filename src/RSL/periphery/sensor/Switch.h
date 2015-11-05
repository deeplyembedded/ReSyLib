/*
 * switch.h
 *
 *      @date 27.10.2015
 *      @author Easy, JI, Daniel, Till
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "../Sensor.h"

namespace RSL {

class Switch: public Sensor {

private:

    /**
     * remembers the active state of the switch (true = HIGH).
     */
    bool activeState;

    /**
     * the first (or only) gpio pin used by the switch.
     */
    GPIO_Digital& pin;

public:

    /**
     * constructor for single poled switches.
     * registers the GPIOPin.
     * @param pin the PIN used by the switch
     */
    Switch(GPIOPin& pin);

    /**
     * destructor that unregisters the GPIOPins
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
    void setActiveState(GPIO_Digital::State state);

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

} /* namespace RSL */

#endif /* SWITCH_H_ */
