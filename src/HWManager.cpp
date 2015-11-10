#include "HWManager.h"

namespace RSL_core {
using namespace RSL_core;

HWManager::HWManager(){}

GPIO& HWManager::createGPIOResource(RSL::GPIOType& type, RSL::GPIOPin& pin) {
	GPIO resource = NULL;

	if (pinsInUse.find(pin) == 0) {
		switch (type) {
		case RSL::DIGITAL:
			resource = RSL::GPIO_Digital(pin);
			break;
		case RSL::PWM:
			break;
		}
	}

	if (resource) {
		resource.initialize();
	}

	return resource;
}

GPIO& HWManager::createGPIOResource(RSL::GPIOType& type,
		std::vector<RSL::GPIOPin>& pins) {
	GPIO resource = NULL;
	bool allPinsFree = true;

	for (auto p : pins) {
		if (pinsInUse.find(p) > 0) {
			allPinsFree = false;
		}
	}

	if (allPinsFree) {
		switch (type) {

		}
	}

	if (resource) {
		resource.initialize();
	}

	return resource;
}

void HWManager::deleteGPIOResource(GPIO& resource) {
	resource.shutdown();
}

void HWManager::allocateGPIOPin(RSL::GPIOPin& pin) {
	pinsInUse.insert(pin);
}

void HWManager::freeGPIOPin(RSL::GPIOPin& pin) {
	pinsInUse.erase(pin);
}
}
;

