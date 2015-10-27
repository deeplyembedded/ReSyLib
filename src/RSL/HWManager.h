#include <vector>

namespace RLS_core {
	class HWManager {
		public:
			GPIO createGPIOResource(RSL::GPIO::GPIOType type, RSL::GPIO::GPIOPin pin);
			GPIO createGPIOResource(RSL::GPIO::GPIOType type, vector<RSL::GPIO::GPIOPin> pins);
			void deleteGPIOResource(RSL::GPIO resource);
	}
}