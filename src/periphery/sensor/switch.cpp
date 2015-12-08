/*
 * switch.cpp
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi, Daniel Sarnow, Till Kaiser
 */

#include "Switch.h"

namespace RSL {

Switch::Switch()
	: activeState(false)
	, pin(nullptr)
{
}

Switch::~Switch() {
	if(isInitialized())
		pin->shutdown();
}

bool Switch::isInitialized() const {
	return pin != nullptr;
}

void Switch::initialize(GPIOPin pin_) {
	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();

	pin = move(unique_ptr<GPIO_Digital>(static_cast<GPIO_Digital*>(hwManager.createGPIOResource(DIGITAL,pin_).release())));

	if(pin == nullptr){
		//TODO: error handling and return / destroy self
	}
	pin->setDirection(INPUT);
}

bool Switch::isPressed() const {
	GPIO_Digital::State pinValue = pin->getValue();
	return (activeState) ? pinValue : !pinValue;
}

void Switch::setActiveState(GPIO_Digital::State state) {
	activeState = (state == GPIO_Digital::HIGH);
}

}
