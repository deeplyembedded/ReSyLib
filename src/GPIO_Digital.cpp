#include "GPIO_Digital.h"
#include <string>
#include <iostream>

namespace RSL {
using namespace RSL;
using namespace std;

GPIO_Digital::GPIO_Digital(const GPIOPin pin) {
	this->pin = pin;
}

void GPIO_Digital::initialize() {
	using namespace std;
	exportPin(pin);

	string gpioPath = "/sys/class/gpio/gpio" + to_string((int) pin);

	directionFileStream.open((gpioPath + "/direction").c_str(),
			fstream::out | fstream::in);
	valueFileStream.open((gpioPath + "/value").c_str(),
			fstream::out | fstream::in);
}

void GPIO_Digital::shutdown() {
	directionFileStream.close();
	valueFileStream.close();
	unExportPin(pin);
}

void GPIO_Digital::setDirection(const Direction direction) {
	valueFileStream.seekg(0);
	directionFileStream.seekg(0);
	switch (direction) {
	case INPUT:
		directionFileStream << "in";
		break;
	case INPUT_PULLDOWN:
		directionFileStream << "in";
		valueFileStream << "0";
		break;
	case INPUT_PULLUP:
		directionFileStream << "in";
		valueFileStream << "1";
		break;
	case OUTPUT:
		directionFileStream << "out";
		break;
	}

	directionFileStream.flush();
	valueFileStream.flush();
}

Direction GPIO_Digital::getDirection() {
	char dir;
	directionFileStream >> dir;
	switch (dir) {
	case 'i':
		return Direction::INPUT;
	default:
		return Direction::OUTPUT;
	}
}

void GPIO_Digital::setValue(const GPIO_Digital::State value) {
	valueFileStream << value;
	valueFileStream.flush();
}

GPIO_Digital::State GPIO_Digital::getValue() {
	string val;
	valueFileStream.seekg(0);
	valueFileStream >> val;

	return (val == "0") ? GPIO_Digital::LOW : GPIO_Digital::HIGH;
}

GPIO_Digital::~GPIO_Digital() {
	shutdown();
}
}

