#include "GPIO.h"
#include <unordered_set>

namespace RSL_core {
class HWManager
{
    public:
        static HWManager& getInstance()
        {
            static HWManager instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        };
		
		GPIO createGPIORessource(RSL::GPIOType type, RSL::GPIOPin pin);
		GPIO createGPIORessource(RSL::GPIOType type, std::vector<RSL::GPIOPin> pins);
		void deleteGPIORessource(GPIO ressource);
		void freeGPIOPin(RSL::GPIOPin pin);
		
    private:
		std::unordered_set<RSL::GPIOPin> pinsInUse;

        HWManager() {}; // Constructor

        HWManager(HWManager const&) = delete;
        void operator=(HWManager const&) = delete;

};
}
