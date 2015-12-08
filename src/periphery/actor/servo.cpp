/*
 * servo.cpp
 *
 *      @date 26.10.2015
 *      @author Yannic, Moritz
 */

#include "../../GPIO.h"
#include "../../GPIO_PWM.h"
#include "../../HWManager.h"
#include "./Servo.h"

namespace RSL {

using namespace RSL_core;

Servo::Servo(GPIOPin servoPin) {
	currentPosition = 0;

	this->servoPin = move(unique_ptr<GPIO_PWM>(static_cast<GPIO_PWM*>(HWManager::getInstance().createGPIOResource(PWM,servoPin).release())));
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

