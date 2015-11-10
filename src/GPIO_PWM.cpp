/*
 * GPIO_PWM.cpp
 *
 *  Created on: 07.11.2015
 *      Author: Yannic
 */

#include "GPIO_PWM.h"
#include <string>

namespace RSL {

using namespace std;
using namespace RSL;

// todo check pin form usability
GPIO_PWM::GPIO_PWM(GPIOPin pin) {
	this->pin = pin;

	polarity = Polarity::PHASED;
	period = 0;
	duty = 0;
	pwmState = PWMState::OFF;
	dutyFileStream = nullptr;
	periodFileStream = nullptr;
	polarityFileStream = nullptr;
	activeFileStream = nullptr;
}

GPIO_PWM::~GPIO_PWM() {
	shutdown();
}

void GPIO_PWM::initialize() {
	std::fstream fileStream;

	exportPin(pin);

	fileStream.open((SLOT_FILE_PATH).c_str(), fstream::out | fstream::in);
	fileStream << "am33xx_pwm";
	fileStream << "bone_pwm_" + getPinNameFromEnum(pin);
	fileStream.flush();
	fileStream.close();

	dutyFileStream.open((PWM_PATH + getPinNameFromEnum(pin) + "/duty").c_str(), fstream::out | fstream::in);
	periodFileStream.open((PWM_PATH + getPinNameFromEnum(pin) + "/period").c_str(), fstream::out | fstream::in);
	polarityFileStream.open((PWM_PATH + getPinNameFromEnum(pin) + "/polarity").c_str(), fstream::out | fstream::in);
	activeFileStream.open((PWM_PATH + getPinNameFromEnum(pin) + "/run").c_str(), fstream::out | fstream::in);

	disablePWM();
	setPeriod(20000000);
	setDuty(1000000 + (1000000 * 0.5));
	setPolarity(GPIO_PWM::Polarity::PHASED);
}

void GPIO_PWM::shutdown() {
	dutyFileStream.close();
	periodFileStream.close();
	polarityFileStream.close();
	activeFileStream.close();

	unExportPin(pin);
}

void GPIO_PWM::setPeriod(unsigned int period) {
	this->period = period;
	periodFileStream << period;
	periodFileStream.flush();
}

unsigned int GPIO_PWM::getPeriod() {
	return period;
}

void GPIO_PWM::setDuty(unsigned int duty) {
	this->duty = duty;
	dutyFileStream << duty;
	dutyFileStream.flush();
}

unsigned int GPIO_PWM::getDuty() {
	return this->duty;
}

void GPIO_PWM::setPolarity(Polarity polarity) {
	this->polarity = polarity;
	polarityFileStream << polarity;
	polarityFileStream.flush();
}

GPIO_PWM::Polarity GPIO_PWM::getPolarity() {
	return polarity;
}

void GPIO_PWM::enablePWM() {
	this->pwmState = GPIO_PWM::PWMState::ON;
	activeFileStream << GPIO_PWM::PWMState::ON;
	activeFileStream.flush();
}

void GPIO_PWM::disablePWM() {
	this->pwmState = GPIO_PWM::PWMState::OFF;
	activeFileStream << GPIO_PWM::PWMState::OFF;
	activeFileStream.flush();
}

GPIO_PWM::PWMState GPIO_PWM::getPWMState() {
	return this->pwmState;
}

string getPinNameFromEnum(GPIOPin pin) {
	switch (pin) {
		case P8_13: return "P8_13";
		case P8_19: return "P8_19";
		case P9_14: return "P9_14";
		case P9_16: return "P9_16";
		case P9_21: return "P9_21";
		case P9_22: return "P9_22";
		case P9_42: return "P9_42";
	};

	return "";
}

}

