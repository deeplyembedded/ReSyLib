#pragma once

#include <fstream>
#include "GPIO.h"

namespace RSL {

using namespace RSL;

class GPIO_Digital : public RSL_core::GPIO {
private:
	std::fstream valueFileStream, directionFileStream;
	GPIOPin pin;

public:
	enum State
		: unsigned int {
			LOW = 0, HIGH = 1
	};

	GPIO_Digital(GPIOPin pin);

	void setDirection(Direction direction);
	Direction getDirection();

	void setValue(State value);
	State getValue();

	~GPIO_Digital();


	void initialize() override;
	void shutdown() override;
};

}
;
