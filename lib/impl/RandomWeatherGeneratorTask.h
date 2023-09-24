//
// Created by beloin on 23/09/23.
//

#ifndef LCD_DHT11_RANDOMWEATHERGENERATORTASK_H
#define LCD_DHT11_RANDOMWEATHERGENERATORTASK_H

#include "drivers/WeatherStatusTask.h"

namespace Sensors {

    class RandomWeatherGeneratorTask : public WeatherStatusTask {

    public:
        [[noreturn]] void operator()(WeatherInfo *) const override;
    };

}

#endif //LCD_DHT11_RANDOMWEATHERGENERATORTASK_H
