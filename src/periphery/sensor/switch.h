/*
 * switch.h
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi, Daniel Sarnow, Till Kaiser
 */

#pragma once

#include <memory>
#include "../Sensor.h"


namespace RSL {

using namespace std;

class Switch: public Sensor {

private:

    /**
     * remembers the active state of the switch (true = HIGH).
     */
    bool activeState;

    /**
     * the first (or only) gpio pin used by the switch.
     */
    unique_ptr<GPIO_Digital> pin;

public:

    /**
     * constructor for single poled switches.
     * registers the GPIOPin.
     * @param pin the PIN used by the switch
     */
    Switch();

    /**
     * destructor that unregisters the GPIOPins
     */
    virtual ~Switch();

    /**
     * check if pin has been initialized
     * @return true if pin has been assigned
     */
    bool isInitialized() const;

    /**
     * initializes switch with GPIO pin
     * @param GPIOPin
     */
    void initialize(GPIOPin pin_);

    /**
     * get the active state of the switch.
     * @return true, if switch is in active state - false otherwise
     */
    bool isPressed() const;

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

