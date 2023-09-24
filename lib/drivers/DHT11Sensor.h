//
// Created by beloin on 24/09/23.
//

#ifndef LCD_DHT11_DHT11SENSOR_H
#define LCD_DHT11_DHT11SENSOR_H

#include "drivers/WeatherStatusTask.h"

namespace Sensors {
    class DHT11Sensor : public WeatherStatusTask {
    public:
        [[noreturn]] void operator()(WeatherInfo *) const override;
    };

}


#endif //LCD_DHT11_DHT11SENSOR_H
