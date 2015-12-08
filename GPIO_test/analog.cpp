#include "../src/GPIO_Analog.h"
#include <unistd.h>
#include <iostream>

int main(int argc, char **argv) {
	using namespace RSL;

	GPIO_Analog analogPin(AINPin::P9_39);

	analogPin.initialize();

	while (true) {
		std::cout << std::to_string(analogPin.getValue()) << endl;
		usleep(500000);
	}
}
