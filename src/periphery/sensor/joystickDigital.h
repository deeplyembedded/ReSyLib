/*
 * joystickDigital.h
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi
 */

#ifndef JOYSTICK_DIGITAL_H_
#define JOYSTICK_DIGITAL_H_

#include <memory>
#include "../Sensor.h"
#include "switch.h"

namespace RSL {

using namespace std;

class JoystickDigital: public Sensor {

private:
	unique_ptr<GPIO_Digital> pinX;
	unique_ptr<GPIO_Digital> pinY;
	RSL::Switch switchObject;

public:

	enum JoystickDirection { NORTH_EAST,SOUTH_EAST,SOUTH_WEST,NORTH_WEST,UNKNOWN };
	/**
	 * which direction has the joystick
	 *
	 * @return the direction as an enum of Type JoystickDirection
	 */
	JoystickDigital::JoystickDirection direction() const;

	/**
	 * check if pins has been initialized
	 * @return true if pins have been assigned
	 */
	bool isInitialized() const;

	/**
	 * initializes joystick with x and y axis pins
	 * @param pinX_
	 * @param pinY_
	 */
	void initialize(GPIOPin pinX_, GPIOPin pinY_);

	/**
	 * initializes joystick with x, y axis and switch pins
	 * @param pinX_
	 * @param pinY_
	 * @param pinSW_
	 */
	void initialize(GPIOPin pinX_, GPIOPin pinY_, GPIOPin pinSW_);

	Switch& getSwitchObject();

	JoystickDigital();
	virtual ~JoystickDigital();

};

} /* namespace RSL */

#endif /* JOYSTICK_DIGITAL_H_ */
