#include <GPIO_Digital.h>
#include <unistd.h>

int main(int argc, char **argv) {
	using namespace RSL;

	GPIO_Digital ledPin(GPIOPin::P9_12);
	ledPin.setDirection(Direction::OUTPUT);

	while (true) {
		ledPin.setValue((GPIO_Digital::State)!ledPin.getValue());
		sleep(1);
	}
}
