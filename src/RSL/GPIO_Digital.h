#include "GPIO.h"

namespace RSL {

	class GPIO_Digital : public RSL_core::GPIO {
		public:
			enum State : signed int {
						LOW = 0,
						HIGH = 1
					};
			GPIO_Digital(){}
			GPIO_Digital(GPIOPin pin){} //TODO implement constructor -> CPP
			
			void initialize() {}        //TODO implement functions in CPP
			void shutdown() {}

			void setDirection(Direction direction);
			Direction getDirection();
			
			void setValue(State value);
			State getValue();
			
			~GPIO_Digital();
	};

};
