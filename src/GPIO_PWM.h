#pragma once

#include "GPIO.h"
#include <fstream>
#include <String>

namespace RSL {

	using namespace RSL_core;
	using namespace RSL;
	using namespace std;

	class GPIO_PWM : public RSL_core::GPIO {
		public:
			enum Polarity: unsigned int {PHASED = 1, DEPHASED = 0};
			enum PWMState: unsigned int {ON=1, OFF=0};

			GPIO_PWM(const GPIOPin pin);
			~GPIO_PWM();

			void initialize();
			void shutdown();

			void setPeriod(const unsigned int period);
			unsigned int getPeriod();

			void setDuty(const unsigned int duty);
			unsigned int getDuty();

			void setPolarity(const Polarity polarity);
			Polarity getPolarity();

			void enablePWM();
			void disablePWM();

			PWMState getPWMState();
		private:
			const string SLOT_FILE_PATH = "/sys/devices/bone_capemgr.9/slots";
			const string PWM_PATH = "/sys/devices/ocp.3/";

			GPIOPin pin;
			Polarity polarity;
			PWMState pwmState;
			unsigned int period, duty;
			std::fstream dutyFileStream, periodFileStream, polarityFileStream, activeFileStream;

			string getPinNameFromEnum(const GPIOPin pin);
			string getPWMNameFromEnum(const GPIOPin pin);
			string findPWMName(const string path, const string pinName);
	};

};

