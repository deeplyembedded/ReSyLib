#include "../src/GPIO_Digital.h"
#include <unistd.h>
#include <iostream>
#include "../src/periphery/sensor/switch.h"

using namespace RSL;
using namespace std;

void oldTest() {
	GPIO_Digital ledPin(GPIOPin::P9_12);
	GPIO_Digital ledPinGreen(GPIOPin::P9_13);
	ledPin.initialize();
	ledPin.setDirection(Direction::OUTPUT);
	ledPinGreen.initialize();
	ledPinGreen.setDirection(Direction::OUTPUT);
	GPIO_Digital switchPin(GPIOPin::P9_16);
	switchPin.initialize();
	switchPin.setDirection(Direction::INPUT);
	while (true) {
		if (switchPin.getValue() == GPIO_Digital::HIGH) {
			ledPin.setValue(GPIO_Digital::State::HIGH);
			ledPinGreen.setValue(GPIO_Digital::State::LOW);
		} else {
			ledPin.setValue(GPIO_Digital::State::LOW);
			ledPinGreen.setValue(GPIO_Digital::State::HIGH);
		}
	}
}

void newTest(){
	Switch switch_(GPIOPin::P9_12);
	switch_.isPressed();
}

int main(int argc, char **argv) {

	//oldTest();

	newTest();

	return 0;
}
