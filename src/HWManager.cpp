#include "HWManager.h"
#include "GPIO_Digital.h"
#include "GPIO_PWM.h"

namespace RSL_core {
using namespace RSL_core;

HWManager::HWManager(){}

std::unique_ptr<GPIO> HWManager::createGPIOResource(const RSL::GPIOType type, const RSL::GPIOPin pin) {
	std::unique_ptr<GPIO> resource = NULL;
	if (pinsInUse.count((int)pin) == 0) {
		if (type==RSL::DIGITAL) {
			resource = std::unique_ptr<RSL::GPIO_Digital>(new RSL::GPIO_Digital(pin));
		} else if (type==RSL::PWM) {
			resource = std::unique_ptr<RSL::GPIO_PWM>(new RSL::GPIO_PWM(pin));
		}
	}

	if (resource != NULL) {
		resource->initialize();
	}

	return resource;
}

std::unique_ptr<GPIO> HWManager::createGPIOResource(const RSL::GPIOType type,
		const std::vector<RSL::GPIOPin>& pins) {
	std::unique_ptr<GPIO> resource = NULL;
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

void HWManager::allocateGPIOPin(const RSL::GPIOPin pin) {
	pinsInUse.insert((int)pin);
}

void HWManager::freeGPIOPin(const RSL::GPIOPin pin) {
	pinsInUse.erase((int)pin);
}
}
;

