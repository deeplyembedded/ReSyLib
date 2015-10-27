/*
 * switch.cpp
 *
 *      @date 27.10.2015
 *      @author Easy, JI, Daniel, Till
 */

#include "switch.h"

Switch::Switch(GPIO::GPIOPin pin){
  if(pin != null){
    //TODO: define GPIOType
    this.pin = (GPIO_Digital)getGPIORessource(GPIO::GPIOType.Digital, pin);
    pin.setDirection(GPIO::Direction.INPUT);
  } else {
    throw new ParamIsNullException();
  }
}

Switch::~Switch(){
    pin.shutdown();
}

bool Switch::isPressed(){
  GPIO_Digital::State pinValue = pin.getValue();
  return (activeState) ? pinValue : !pinValue;
}

void Switch::setActiveState(GPIO_Digital::State state){
  if(state != null){
    if(state == GPIO_Digital::State.HIGH){
      activeState = true;
    } else {
      activeState = false;
    }
  }
}
