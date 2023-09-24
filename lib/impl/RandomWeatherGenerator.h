//
// Created by beloin on 23/09/23.
//

#ifndef LCD_DHT11_RANDOMWEATHERGENERATOR_H
#define LCD_DHT11_RANDOMWEATHERGENERATOR_H

#include "drivers/WeatherStatusTask.h"

namespace Sensors {

    class RandomWeatherGenerator : public WeatherStatusTask {

    public:
        [[noreturn]] void operator()(WeatherInfo *) const override;
    };

}

#endif //LCD_DHT11_RANDOMWEATHERGENERATOR_H
