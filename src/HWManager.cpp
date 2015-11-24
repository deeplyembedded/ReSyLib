#include "HWManager.h"
#include "GPIO_Digital.h"

namespace RSL_core {
using namespace RSL_core;

HWManager::HWManager(){}

GPIO* HWManager::createGPIOResource(RSL::GPIOType type, RSL::GPIOPin pin) {
	GPIO* resource;
	if (pinsInUse.count((int)pin) == 0) {
		if (type==RSL::DIGITAL) {
			resource = new RSL::GPIO_Digital(pin);
		} else if (type==RSL::PWM) {

		}
	}

	if (resource != NULL) {
		resource->initialize();
	}

	return resource;
}

GPIO* HWManager::createGPIOResource(RSL::GPIOType type,
		std::vector<RSL::GPIOPin>& pins) {
	GPIO* resource = NULL;
	bool allPinsFree = true;

	for (auto p : pins) {
		if (pinsInUse.count((int)p) > 0) {
			allPinsFree = false;
		}
	}

	if (allPinsFree) {
		// add new GPIOs here
	}

	if (resource != NULL) {
		resource->initialize();
	}

	return resource;
}

void HWManager::deleteGPIOResource(GPIO* resource) {
	resource->shutdown();
}

void HWManager::allocateGPIOPin(RSL::GPIOPin pin) {
	pinsInUse.insert((int)pin);
}

void HWManager::freeGPIOPin(RSL::GPIOPin pin) {
	pinsInUse.erase((int)pin);
}
}
;

