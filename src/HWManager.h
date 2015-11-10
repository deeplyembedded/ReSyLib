#pragma once

#include "GPIO.h"
#include <unordered_set>
#include <vector>

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
		
		GPIO* createGPIOResource(RSL::GPIOType type, RSL::GPIOPin pin);
		GPIO* createGPIOResource(RSL::GPIOType type, std::vector<RSL::GPIOPin>& pins);
		void deleteGPIOResource(GPIO* resource);

		void allocateGPIOPin(RSL::GPIOPin pin);
		void freeGPIOPin(RSL::GPIOPin pin);
		
    private:
		std::unordered_set<int> pinsInUse;

        HWManager(); // Constructor

        HWManager(HWManager const&) = delete;
        void operator=(HWManager const&) = delete;

};
}
