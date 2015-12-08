/*
 * GPIO_PWM.cpp
 *
 *  Created on: 07.11.2015
 *      Author: Yannic
 */

#include "GPIO_PWM.h"
#include <string.h>
#include <dirent.h>
#include <string>
#include <iostream>
#include <unistd.h>

namespace RSL {

using namespace std;
using namespace RSL;

// todo check pin form usability
GPIO_PWM::GPIO_PWM(const GPIOPin pin) {
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
	string pwmPinPath;

	exportPin(pin);

	fileStream.open((SLOT_FILE_PATH).c_str(), fstream::out | fstream::in);
	fileStream << "am33xx_pwm";
	fileStream.flush();

	fileStream << "bone_pwm_" + GPIO_PWM::getPinNameFromEnum(pin);
	fileStream.flush();
	fileStream.close();
	usleep(2000000);

	pwmPinPath = PWM_PATH + getPWMNameFromEnum(pin);
	std::cout << "'" << pwmPinPath << "'" << endl;

	dutyFileStream.open((pwmPinPath + "/duty").c_str(), fstream::out | fstream::in);
	//dutyFileStream << "1000000";
	periodFileStream.open((pwmPinPath + "/period").c_str(), fstream::out | fstream::in);
	//setPeriod(20000000);
	polarityFileStream.open((pwmPinPath + "/polarity").c_str(), fstream::out | fstream::in);
	//polarityFileStream << "0";
	activeFileStream.open((pwmPinPath + "/run").c_str(), fstream::out | fstream::in);
	//activeFileStream << "1";

	if (dutyFileStream.fail())
		std::cout << "alles kaputt!" << endl;

	//setPolarity(GPIO_PWM::Polarity::PHASED);
	//disablePWM();
	//setPeriod(0);
	//setDuty(0);

}

void GPIO_PWM::shutdown() {
	dutyFileStream.close();
	periodFileStream.close();
	polarityFileStream.close();
	activeFileStream.close();

	unExportPin(pin);
}

void GPIO_PWM::setPeriod(const unsigned int period) {
	this->period = period;
	periodFileStream << to_string(period);
	periodFileStream.flush();
}

unsigned int GPIO_PWM::getPeriod() {
	return period;
}

void GPIO_PWM::setDuty(const unsigned int duty) {
	this->duty = duty;
	dutyFileStream << to_string(duty);
	dutyFileStream.flush();
}

unsigned int GPIO_PWM::getDuty() {
	return this->duty;
}

void GPIO_PWM::setPolarity( const Polarity polarity) {
	this->polarity = polarity;
	polarityFileStream << to_string(polarity);
	polarityFileStream.flush();
}

GPIO_PWM::Polarity GPIO_PWM::getPolarity() {
	return polarity;
}

void GPIO_PWM::enablePWM() {
	this->pwmState = GPIO_PWM::PWMState::ON;
	activeFileStream << to_string(GPIO_PWM::PWMState::ON);
	activeFileStream.flush();
}

void GPIO_PWM::disablePWM() {
	this->pwmState = GPIO_PWM::PWMState::OFF;
	activeFileStream << to_string(GPIO_PWM::PWMState::OFF);
	activeFileStream.flush();
}

GPIO_PWM::PWMState GPIO_PWM::getPWMState() {
	return this->pwmState;
}

string GPIO_PWM::getPinNameFromEnum(const GPIOPin pin) {
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

string GPIO_PWM::getPWMNameFromEnum(const GPIOPin pin) {
	string tmpPath = getPinNameFromEnum(pin);

	if (tmpPath != "") {
		return findPWMName(PWM_PATH, "pwm_test_" + tmpPath);
	} else {
		return "";
	}
}

string GPIO_PWM::findPWMName(const string path, const string pinName) {
	DIR* openedDir = opendir(path.c_str());
	struct dirent* readDir;

	if (openedDir) {

		while((readDir = readdir(openedDir)) != 0) {
			if (strstr(readDir->d_name, pinName.c_str()) != 0) {
				closedir(openedDir);
				return readDir->d_name;
			}
		}

		closedir(openedDir);
	}

	return "";
}

}

