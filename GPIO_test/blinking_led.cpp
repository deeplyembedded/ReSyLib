#include "../src/GPIO_PWM.h"
#include <unistd.h>
#include <iostream>

int main(int argc, char **argv) {
	using namespace RSL;

	GPIO_PWM servoPin(GPIOPin::P9_14);

	servoPin.initialize();

	servoPin.setPolarity(GPIO_PWM::Polarity::DEPHASED);
	servoPin.setPeriod(20000000);
	servoPin.enablePWM();
	servoPin.setDuty(1000000);


	while (true) {
		servoPin.setDuty(1000000);
		std::cout << "1" << endl;
		sleep(1);
		servoPin.setDuty(1700000);
		std::cout << "2" << endl;
		sleep(1);
	}
}
