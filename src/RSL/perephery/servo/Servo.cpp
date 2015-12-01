/*
 * servo.cpp
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */

#include "../../../GPIO.h"
#include "../../../GPIO_PWM.h"
#include "../../../HWManager.h"
#include "./Servo.h"

namespace RSL {

using namespace RSL_core;

Servo::Servo(GPIOPin servoPin) {
	currentPosition = 0;

	this->servoPin = (GPIO_PWM*)HWManager::getInstance().createGPIOResource(GPIOType::PWM, servoPin);
}

Servo::~Servo() {
	// todo use interfaces for unregister servo
	// todo release pin stuff (set to default settings)
}

double Servo::getPosition(void) {
	return currentPosition;
}

void Servo::setPosition(double position) {
	currentPosition = position;

	// todo check for min max value
	servoPin->setDuty(1000000 + (1000000 * position));
}

void Servo::enableServo() {
	servoPin->enablePWM();
}

void Servo::disableServo() {
	servoPin->disablePWM();
}

}

