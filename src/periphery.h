/*
 * Periphery.h
 *
 *  @date   03.11.2015
 *  @author Easy, Jannik Iacobi, Daniel Sarnow, Till Kaiser
 */

#ifndef SRC_RSL_PERIPHERY_H_
#define SRC_RSL_PERIPHERY_H_

#include "GPIO_Digital.h"

namespace RSL {

class Periphery {
public:
    Periphery();
    virtual ~Periphery();

    RSL_core::GPIO& getGPIOResource(GPIOType type, GPIOPin& pin);
};

} /* namespace RSL */

#endif /* SRC_RSL_PERIPHERY_H_ */
