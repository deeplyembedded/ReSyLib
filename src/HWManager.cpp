#include "HWManager.h"
#include "GPIO_Digital.h"
#include "GPIO_PWM.h"

namespace RSL_core {
using namespace RSL_core;

HWManager::HWManager() {
}

bool HWManager::pinsFree(const RSL::GPIOPin pin) {
	// TODO: sinnvolle Implementierung, wenn benötigt
	return true;
}

bool HWManager::pinsFree(const std::vector<RSL::GPIOPin>& pins) {
	// TODO: sinnvolle Implementierung, wenn benötigt
	return true;
}

void HWManager::allocateGPIOPin(const RSL::GPIOPin pin) {
	pinsInUse.insert((int) pin);
}

void HWManager::freeGPIOPin(const RSL::GPIOPin pin) {
	pinsInUse.erase((int) pin);
}
}
;

