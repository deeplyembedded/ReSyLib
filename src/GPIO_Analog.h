#pragma once

#include "GPIO.h"
#include <fstream>
#include <String>

namespace RSL {

	using namespace RSL_core;
	using namespace RSL;
	using namespace std;

	class GPIO_Analog : public RSL_core::GPIO {
		public:
			GPIO_Analog(AINPin pin);
			~GPIO_Analog();

			void initialize();
			void shutdown();

			unsigned int getValue();

		private:
			const string SLOT_FILE_PATH = "/sys/devices/bone_capemgr.9/slots";
			string analog_path = "/sys/devices/ocp.3/";
			static bool initialized;

			AINPin pin;
			std::fstream valueFileStream;

			string findHelperPath(string containingDir);
	};

};

