#include "../src/GPIO_Digital.h"
#include <unistd.h>
#include <iostream>

using namespace RSL;
using namespace std;

int main(int argc, char **argv) {

	GPIO_Digital ledPin(GPIOPin::P9_12);
	ledPin.initialize();
	ledPin.setDirection(Direction::OUTPUT);


	GPIO_Digital switchPin(GPIOPin::P9_16);
	switchPin.initialize();
	switchPin.setDirection(Direction::INPUT);

	while (true) {
		if(switchPin.getValue() == GPIO_Digital::HIGH)
			ledPin.setValue(GPIO_Digital::State::HIGH);
		else
			ledPin.setValue(GPIO_Digital::State::LOW);
	}
	return 0;
}
