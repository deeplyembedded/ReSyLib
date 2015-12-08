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

JoystickDigital::JoystickDigital(GPIOPin pinX_, GPIOPin pinY_) {
	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();
	if (&hwManager != NULL) {
		pinX = (GPIO_Digital*) hwManager.createGPIOResource(DIGITAL, pinX_);
		pinY = (GPIO_Digital*) hwManager.createGPIOResource(DIGITAL, pinY_);
		pinSW = NULL;
		if (pinX != NULL && pinY != NULL) {
			pinX->setDirection(INPUT);
			pinY->setDirection(INPUT);
		} else {
			//TODO: error handling and return / destroy self
		}
	} else {
		//TODO: error handling and return / destroy self
	}
}

JoystickDigital::JoystickDigital(GPIOPin pinX_, GPIOPin pinY_, GPIOPin pinSW_) {
	RSL_core::HWManager& hwManager = RSL_core::HWManager::getInstance();
	if (&hwManager != NULL) {
		pinX = (GPIO_Digital*) hwManager.createGPIOResource(DIGITAL, pinX_);
		pinY = (GPIO_Digital*) hwManager.createGPIOResource(DIGITAL, pinY_);
		pinSW = (GPIO_Digital*) hwManager.createGPIOResource(DIGITAL, pinSW_);
		if (pinX != NULL && pinY != NULL && pinSW != NULL) {
			pinX->setDirection(INPUT);
			pinY->setDirection(INPUT);
			pinSW->setDirection(INPUT);
		} else {
			//TODO: error handling and return / destroy self
		}
	} else {
		//TODO: error handling and return / destroy self
	}
}

JoystickDigital::~JoystickDigital() {
	if(pinSW != NULL)
		pinSW->shutdown();
	if(pinX != NULL)
		pinX->shutdown();
	if(pinY != NULL)
		pinY->shutdown();

}

JoystickDigital::JoystickDirection JoystickDigital::direction() {
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
