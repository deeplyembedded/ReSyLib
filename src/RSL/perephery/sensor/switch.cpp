/*
 * switch.cpp
 *
 *      @date 22.10.2015
 *      @author Easy, JI
 */
 
#include "switch.h"
 
Switch::Switch(GPIOPIN pin1){ 
  if(pin1 != null){
    //TODO: use GPIO / PIN Interface
    GPIO.registerPIN(pin1);
    GPIO.setPINMode(pin1,INPUT);
    this.pin1 = pin1;
    this.pin2 = null;
    this.doublePole = false;
  } else {
    throw new ParamIsNullException();
  }
}

Switch::Switch(GPIOPIN pin1, GPIOPIN pin2){ 
  if(pin1 != null && pin2 != null){ 
    //TODO: use GPIO / PIN Interface
    GPIO.registerPIN(pin1);
    GPIO.setPINMode(pin1,INPUT);
    GPIO.registerPIN(pin2);
    GPIO.setPINMode(pin2,INPUT);
    this.pin1 = pin1;
    this.pin2 = pin2;
    this.doublePole = true;
  } else {
    throw new ParamIsNullException();
  }
}

Switch::~Switch(){ 
  //TODO: use GPIO / PIN Interface
  GPIO.setPINMode(pin1, NOTHING);
  GPIO.unregisterPIN(pin1);
  if(doublePole){
    GPIO.setPINMode(pin2, NOTHING);
    GPIO.unregisterPIN(pin2);
  }
}

bool Switch::isPressed(){ 
  bool pin1Value = GPIO.getPINValue(pin1);;
  if(doublePole){
    bool pin2Value = GPIO.getPINValue(pin2);
    if(pin1Value == pin2Value){
      throw new DoublePoleSwitchException("Both PIN values are equal!");
    }
  }
  return (activeState) ? pin1Vaue : !pin1Value;
}

void Switch::setActiveState(GPIOSTATE state){ 
  if(state != null){
    if(state == GPIOSTATE.HIGH){
      //TODO: use GPIO / PIN Interface
      GPIO.setPullDown(pin1);
      if(doublePole){
        GPIO.setPullDown(pin2);
      }
      activeState = true;
    } else {
      GPIO.setPullUp(pin1);
      if(doublePole){
        GPIO.setPullUp(pin2);
      }
      activeState = false;
    }
  }
}