#pragma once

#include <unordered_set>
#include <vector>
#include <memory>
#include <type_traits>
#include "GPIO.h"
#include "Util.h"

namespace RSL_core {
class HWManager {
public:
	static HWManager& getInstance() {
		static HWManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
	;

	template<typename T> std::unique_ptr<T> createGPIOResource(
			const RSL::GPIOPin pin);
	template<typename T> std::unique_ptr<T> createGPIOResource(
			const std::vector<RSL::GPIOPin>& pins);

	void allocateGPIOPin(const RSL::GPIOPin pin);
	void freeGPIOPin(const RSL::GPIOPin pin);

private:
	std::unordered_set<int> pinsInUse;

	HWManager(); // Constructor

	HWManager(HWManager const&) = delete;
	void operator=(HWManager const&) = delete;

	bool pinsFree(const RSL::GPIOPin pin);
	bool pinsFree(const std::vector<RSL::GPIOPin>& pins);

};

using namespace std;

template<typename T>
unique_ptr<T> HWManager::createGPIOResource(const RSL::GPIOPin pin) {
	static_assert(is_base_of<GPIO, T>::value, "HWManager::createGPIOResource can only create GPIOs!");

	unique_ptr<T> resource = NULL;
	if (pinsFree(pin)) {
		resource = make_unique<T>(pin);
	}

	if (resource != NULL) {
		resource->initialize();
	}

	return resource;
}

template<typename T>
unique_ptr<T> HWManager::createGPIOResource(const vector<RSL::GPIOPin>& pins) {
	static_assert(is_base_of<GPIO, T>::value, "HWManager::createGPIOResource can only create GPIOs!");

	unique_ptr<T> resource = NULL;
	if (pinsFree(pins)) {
		resource = make_unique<T>(pins);
	}

	if (resource != NULL) {
		resource->initialize();
	}

	return resource;
}
}
