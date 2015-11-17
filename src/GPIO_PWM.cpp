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
}

GPIO_PWM::~GPIO_PWM() {
	shutdown();
}

void GPIO_PWM::initialize() {
	std::fstream fileStream;

	exportPin(pin);

	fileStream.open((SLOT_FILE_PATH).c_str(), fstream::out | fstream::in);
	fileStream.seekg(0);
	fileStream << "am33xx_pwm";
	fileStream.flush();
	fileStream.seekg(0);
	fileStream << "bone_pwm_" + GPIO_PWM::getPinNameFromEnum(pin);
	fileStream.flush();
	fileStream.close();

	dutyFileStream.open((PWM_PATH + getPWMNameFromEnum(pin) + "/duty").c_str(), fstream::out | fstream::in);
	periodFileStream.open((PWM_PATH + getPWMNameFromEnum(pin) + "/period").c_str(), fstream::out | fstream::in);
	polarityFileStream.open((PWM_PATH + getPWMNameFromEnum(pin) + "/polarity").c_str(), fstream::out | fstream::in);
	activeFileStream.open((PWM_PATH + getPWMNameFromEnum(pin) + "/run").c_str(), fstream::out | fstream::in);

	disablePWM();
	setPeriod(0);
	setDuty(0);
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
	periodFileStream.seekg(0);
	periodFileStream << period;
	periodFileStream.flush();
}

unsigned int GPIO_PWM::getPeriod() {
	return period;
}

void GPIO_PWM::setDuty(unsigned int duty) {
	this->duty = duty;
	dutyFileStream.seekg(0);
	dutyFileStream << duty;
	dutyFileStream.flush();
}

unsigned int GPIO_PWM::getDuty() {
	return this->duty;
}

void GPIO_PWM::setPolarity(Polarity polarity) {
	this->polarity = polarity;
	polarityFileStream.seekg(0);
	polarityFileStream << polarity;
	polarityFileStream.flush();
}

GPIO_PWM::Polarity GPIO_PWM::getPolarity() {
	return polarity;
}

void GPIO_PWM::enablePWM() {
	this->pwmState = GPIO_PWM::PWMState::ON;
	activeFileStream.seekg(0);
	activeFileStream << 1;// debug GPIO_PWM::PWMState::ON;
	activeFileStream.flush();
}

void GPIO_PWM::disablePWM() {
	this->pwmState = GPIO_PWM::PWMState::OFF;
	activeFileStream.seekg(0);
	activeFileStream << 0;// debug GPIO_PWM::PWMState::OFF;
	activeFileStream.flush();
}

GPIO_PWM::PWMState GPIO_PWM::getPWMState() {
	return this->pwmState;
}

string GPIO_PWM::getPinNameFromEnum(GPIOPin pin) {
	switch (pin) {
		case P8_13: return "P8_13";
		case P8_19: return "P8_19";
		case P9_14: return "P9_14";
		case P9_16: return "P9_16";
		case P9_21: return "P9_21";
		case P9_22: return "P9_22";
		case P9_42: return "P9_42";
		default: return "";
	};

	return "";
}

string GPIO_PWM::getPWMNameFromEnum(GPIOPin pin) {
	switch (pin) {
		case P8_13: return "P8_13";
		case P8_19: return "P8_19";
		case P9_14: return "pwm_test_P9_14.15";
		case P9_16: return "P9_16";
		case P9_21: return "P9_21";
		case P9_22: return "P9_22";
		case P9_42: return "P9_42";
		default: return "";
	};

	return "";
}

}

