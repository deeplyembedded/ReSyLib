/*
 * joystickDigital.cpp
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi
 */

#include "joystickDigital.h"

namespace RSL {

/**
 * KY-023 Joystick Modul (XY-Achsen)
 * X und Y Position des Joysticks, werden als analoge Spannung auf den Ausgangspins ausgegeben.
 */

JoystickDigital::JoystickDigital() : pinX(nullptr),pinY(nullptr),pinSW(nullptr){

}

bool JoystickDigital::isInitialized() const {
	return ((pinX != nullptr) && (pinX != nullptr));
}

Switch JoystickDigital::getSwitchObject(){
	return switchObject;
}

void JoystickDigital::initialize(GPIOPin pinX_, GPIOPin pinY_) {
 	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();
	if (&hwManager != NULL) {
		pinX = (unique_ptr<GPIO_Digital>) hwManager.createGPIOResource(DIGITAL, pinX_);
		pinY = (unique_ptr<GPIO_Digital>) hwManager.createGPIOResource(DIGITAL, pinY_);
		pinSW = nullptr;
		if (pinX != nullptr && pinY != nullptr) {
			pinX->setDirection(INPUT);
			pinY->setDirection(INPUT);
		} else {
			//TODO: error handling and return / destroy self
		}
	} else {
		//TODO: error handling and return / destroy self
	}
 }

void JoystickDigital::initialize(GPIOPin pinX_, GPIOPin pinY_, GPIOPin pinSW_) {
 	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();
	if (&hwManager != NULL) {
		pinX = (unique_ptr<GPIO_Digital>) hwManager.createGPIOResource(DIGITAL, pinX_);
		pinY = (unique_ptr<GPIO_Digital>) hwManager.createGPIOResource(DIGITAL, pinY_);
		switchObject = Switch(pinSW_);
		if (pinX != nullptr && pinY != nullptr && pinSW != nullptr) {
			pinX->setDirection(INPUT);
			pinY->setDirection(INPUT);
		} else {
			//TODO: error handling and return / destroy self
		}
	} else {
		//TODO: error handling and return / destroy self
	}
 }

JoystickDigital::~JoystickDigital() {
	if(pinX != nullptr)
		pinX->shutdown();
	if(pinY != nullptr)
		pinY->shutdown();

}

JoystickDigital::JoystickDirection JoystickDigital::direction() const {
	JoystickDigital::JoystickDirection result = UNKNOWN;
	switch (pinX->getValue()) {
		case GPIO_Digital::HIGH:
			switch (pinY->getValue()) {
				case GPIO_Digital::HIGH:
					result = SOUTH_EAST;
					break;
				case GPIO_Digital::LOW:
					result = NORTH_EAST;
					break;
			}
			break;
		case GPIO_Digital::LOW:
			switch (pinY->getValue()) {
				case GPIO_Digital::HIGH:
					result = SOUTH_WEST;
					break;
				case GPIO_Digital::LOW:
					result = NORTH_WEST;
					break;
			}
			break;
	}
	return result;
}

} // namespace
