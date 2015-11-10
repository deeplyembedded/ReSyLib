#include "HWManager.h"

namespace RSL_core {
using namespace RSL_core;

GPIO HWManager::createGPIORessource(RSL::GPIOType type, RSL::GPIOPin pin) {
	GPIO ressource;

	if (pinsInUse.find(pin) == 0) {
		switch (type) {
		case RSL::DIGITAL:
			ressource = RSL::GPIO_Digital(pin);
			break;
		case RSL::PWM:
			break;
		}
	}

	if (ressource) {
		ressource.initialize();
		// add pins to pinsInUse here?
	}

	return ressource;
}

GPIO HWManager::createGPIORessource(RSL::GPIOType type,
		std::vector<RSL::GPIOPin> pins) {
	GPIO ressource;
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

	if (ressource) {
		ressource.initialize();
		// add pins to pinsInUse here?
	}

	return ressource;
}

void HWManager::deleteGPIORessource(GPIO ressource) {
	ressource.shutdown();
}

void HWManager::freeGPIOPin(RSL::GPIOPin pin) {
	pinsInUse.erase(pin);
}
}
;

