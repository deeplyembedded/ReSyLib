#include "GPIO.h"
#include <fstream>

namespace RSL_core {
using namespace RSL_core;

void GPIO::exportPin(RSL::GPIOPin pin) {
	std::fstream fileStream;
	fileStream.open("/sys/class/gpio/export", std::fstream::out);
	fileStream << pin;
	fileStream.close();
}

void GPIO::unExportPin(RSL::GPIOPin pin) {
	std::fstream fileStream;
	fileStream.open("/sys/class/gpio/unexport", std::fstream::out);
	fileStream << pin;
	fileStream.close();
}
}
;

