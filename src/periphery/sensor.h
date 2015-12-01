/*
 * Sensor.h
 *
 *  @date   03.11.2015
 *  @author Easy, Jannik Iacobi, Daniel Sarnow, Till Kaiser
 */

#ifndef SRC_RSL_PERIPHERY_SENSOR_H_
#define SRC_RSL_PERIPHERY_SENSOR_H_

#include "../Periphery.h"
#include "../HWManager.h"

namespace RSL {

class Sensor : public Periphery {
public:
    Sensor();
    virtual ~Sensor();
};

} /* namespace RSL */

#endif /* SRC_RSL_PERIPHERY_SENSOR_H_ */
