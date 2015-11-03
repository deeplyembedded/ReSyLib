/*
 * switch.cpp
 *
 *      @date 2.12.2015
 *      @author Easy, JI, Daniel, Till
 */

#include "Switch.h"


namespace RSL {

Switch::Switch(GPIOPin pin) {
    activeState = false;
    Switch::pin = (GPIO_Digital)getGPIORessource(DIGITAL, pin);
    Switch::pin.setDirection(INPUT);
}

Switch::~Switch(){
    pin.shutdown();
}

bool Switch::isPressed(){
    GPIO_Digital::State pinValue = pin.getValue();
    return (activeState) ? pinValue : !pinValue;
}

void Switch::setActiveState(GPIO_Digital::State state){
    activeState = (state == GPIO_Digital::HIGH);
}

}
