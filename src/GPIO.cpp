#include "GPIO.h"
#include <fstream>

namespace RSL_core {
using namespace RSL_core;

void GPIO::exportPin(const RSL::GPIOPin pin) {
	std::fstream fileStream;
	fileStream.open("/sys/class/gpio/export", std::fstream::out);
	fileStream << pin;
	fileStream.close();
}

void GPIO::unExportPin(const RSL::GPIOPin pin) {
	std::fstream fileStream;
	fileStream.open("/sys/class/gpio/unexport", std::fstream::out);
	fileStream << pin;
	fileStream.close();
}
}
;

