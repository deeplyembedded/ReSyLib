/*
 * joystickDigital.h
 *
 *      @date 01.12.2015
 *      @author Easy, Jannik Iacobi
 */

#ifndef JOYSTICK_DIGITAL_H_
#define JOYSTICK_DIGITAL_H_

#include "../Sensor.h"

namespace RSL {

class JoystickDigital: public Sensor {

private:
	RSL::GPIO_Digital* pinX;
	RSL::GPIO_Digital* pinY;
	RSL::GPIO_Digital* pinSW;

public:

	enum JoystickDirection { NORTH_EAST,SOUTH_EAST,SOUTH_WEST,NORTH_WEST,UNKNOWN };
	/**
	 * which direction has the joystick
	 *
	 * @return the direction as an enum of Type JoystickDirection
	 */
	JoystickDigital::JoystickDirection direction();
	JoystickDigital(GPIOPin pinX_, GPIOPin pinY_);
	JoystickDigital(GPIOPin pinX_, GPIOPin pinY_, GPIOPin pinSW_);
	virtual ~JoystickDigital();

};

} /* namespace RSL */

#endif /* JOYSTICK_DIGITAL_H_ */
