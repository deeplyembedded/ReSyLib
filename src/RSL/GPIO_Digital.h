namespace RLS {

	class GPIO_Digital {
		public:
			enum State : signed int {
						LOW = 0,
						HIGH = 1,
						FLOATING = -1
					};

			GPIO_Digital(GPIOPin pin);
			
			void setDirection(Direction direction);
			Direction getDirection();
			
			void setValue(State value);
			State getValue();
			
			~GPIO_Digital();
	};

};