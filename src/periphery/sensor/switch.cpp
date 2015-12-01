/*
 * switch.cpp
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi, Daniel Sarnow, Till Kaiser
 */

#include "Switch.h"


namespace RSL {

Switch::Switch(GPIOPin pin_)
    : activeState(false)
{
	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();
	if(&hwManager == NULL){
		//TODO: error handling and return / destroy self
	}
	pin = (GPIO_Digital*)hwManager.createGPIOResource(DIGITAL,pin_);
	if(pin == NULL){
		//TODO: error handling and return / destroy self
	}
	pin->setDirection(INPUT);
}

Switch::~Switch(){
    pin->shutdown();
}

bool Switch::isPressed(){
    GPIO_Digital::State pinValue = pin->getValue();
    return (activeState) ? pinValue : !pinValue;
}

void Switch::setActiveState(GPIO_Digital::State state){
    activeState = (state == GPIO_Digital::HIGH);
}

}
