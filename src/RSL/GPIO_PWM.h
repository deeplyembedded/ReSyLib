using std::string;

namespace RLS {

	class GPIO_PWM {
		public:
			enum Polarity : unsigned int {
						PHASED = 1,
						DEPHASED = 0
					};

			virtual GPIO_PWM(GPIOPin pin);
			
			virtual void setPeriod(unsigned int period);
			virtual unsigned int getPeriod();
			
			virtual void setDuty(unsigned int period);
			virtual unsigned int getDuty();
			
			virtual void setPolarity(Polarity polarity);
			virtual Polarity getPolarity();
			
			virtual ~GPIO_PWM();
	};

};