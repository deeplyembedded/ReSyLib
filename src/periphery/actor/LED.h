//
// Created by Marc on 09.11.2015.
//

#ifndef RESYLIB_LED_H
#define RESYLIB_LED_H

//#include "../actor.h"
#include "../../GPIO.h"
#include "../../GPIO_Digital.h"
#include "../../HWManager.h"
#include <memory>

namespace RSL {

using namespace RSL_core;
using namespace std;

class LED {

private:

	/**
	 * remembers whether the LED is on (true = on)
	 */
	bool _isOn;

	/**
	 * The GPIO pin used by the LD.
	 */
	unique_ptr<GPIO_Digital> _gpio_d;

public:

	/**
	 * Constructor for the LED, the given pin will be registered.
	 */
	LED(const GPIOPin pin);

	/**
	 * Switches the LED on.
	 */
	void on();

	/**
	 * Switches the LED off.
	 */
	void off();

	/**
	 * If on switches off, if off switches on.
	 */
	void toggle();

	/**
	 * Destructor that unregisters the GPIO-pin
	 */
	~LED();
};

}

#endif //RESYLIB_LED_H
