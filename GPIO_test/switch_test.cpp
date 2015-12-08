#include "../src/GPIO_Digital.h"
#include <unistd.h>
#include <iostream>
#include "../src/periphery/sensor/switch.h"
#include "../src/periphery/actor/LED.h"
#include "../src/periphery/sensor/joystickDigital.h"

using namespace RSL;
using namespace std;

void switchTest() {
	bool switch_state = false;
	Switch switch_;
	switch_.initialize(GPIOPin::P9_12);
	LED led_(GPIOPin::P9_13);
	while (1) {
		if (switch_.isPressed() != switch_state) {
			if (switch_.isPressed()) {
				led_.toggle();
			}
			switch_state = !switch_state;
		}

	}
}

void joyDTest(){
	JoystickDigital joy_(GPIOPin::P9_21,GPIOPin::P9_22);
	LED ledNW_(GPIOPin::P9_11);
	LED ledNE_(GPIOPin::P9_12);
	LED ledSW_(GPIOPin::P9_15);
	LED ledSE_(GPIOPin::P9_16);
	JoystickDigital::JoystickDirection oldVal = JoystickDigital::UNKNOWN;
	while(1){
		JoystickDigital::JoystickDirection newVal = joy_.direction();
		if(newVal != oldVal){
			oldVal = newVal;
			ledNE_.off();
			ledNW_.off();
			ledSE_.off();
			ledSW_.off();
			switch(joy_.direction()){
			case JoystickDigital::NORTH_WEST:
				ledNW_.on();
				break;
			case JoystickDigital::NORTH_EAST:
				ledNE_.on();
				break;
			case JoystickDigital::SOUTH_EAST:
				ledSE_.on();
				break;
			case JoystickDigital::SOUTH_WEST:
				ledSW_.on();
				break;
			case JoystickDigital::UNKNOWN:
				break;
			}
		}
	}
}

int main(int argc, char **argv) {

	joyDTest();

	//switchTest();

	return 0;
}
