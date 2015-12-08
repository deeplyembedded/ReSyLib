#pragma once

#include "GPIO.h"
#include <unordered_set>
#include <vector>
#include <memory>

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
		
        std::unique_ptr<GPIO> createGPIOResource(const RSL::GPIOType type, const RSL::GPIOPin pin);
        std::unique_ptr<GPIO> createGPIOResource(const RSL::GPIOType type, const std::vector<RSL::GPIOPin>& pins);

		void allocateGPIOPin(const RSL::GPIOPin pin);
		void freeGPIOPin(const RSL::GPIOPin pin);
		
    private:
		std::unordered_set<int> pinsInUse;

        HWManager(); // Constructor

        HWManager(HWManager const&) = delete;
        void operator=(HWManager const&) = delete;

};
}
