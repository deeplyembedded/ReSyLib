//
// Created by marc on 26.10.15.
//

#include "./LED.h"
#include <memory>
namespace RSL {

/**
 * Constructor of the LED.
 */
LED::LED(const GPIOPin pin) {
	//TODO : Check if casting possible
	_gpio_d = move(unique_ptr<GPIO_Digital>(static_cast<GPIO_Digital*>(HWManager::getInstance().createGPIOResource(DIGITAL,pin).release())));

	//Set direction to output.
	_gpio_d->setDirection(RSL::OUTPUT);

	off();

}

LED::~LED(void) {
	//TODO Unexport the pin once finished.
}

/**
 * Switch the LED on.
 */
void LED::on() {
	//Set value to 1/Toggle the LED on.
	_gpio_d->setValue(RSL::GPIO_Digital::HIGH);

	_isOn = true;
}

/**
 * Switch the LED off.
 */
void LED::off() {
	//Set value to 0/Toggle the LED off.
	_gpio_d->setValue(RSL::GPIO_Digital::LOW);

	_isOn = false;
}

/**
 * Toggle between on and off.
 */
void LED::toggle() {
	if (_isOn) {
		off(); //If on switch off
	} else {
		on(); //If off switch on
	}
}
}
