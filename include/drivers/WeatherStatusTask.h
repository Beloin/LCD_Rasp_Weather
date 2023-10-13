//
// Created by beloin on 23/09/23.
//

#ifndef LCD_DHT11_WEATHERSTATUSTASK_H
#define LCD_DHT11_WEATHERSTATUSTASK_H

#include <string>

namespace Sensors {

    enum Status {
        Error = -1,
        Imprecise = 1,
        Ok = 0
    };

    std::string StatusToString(Status status);

    struct WeatherInfo {
        Status status;
        float temperature;
        float humidity;
    };

    /**
     * Task that runs updating WeatherInfo.
     */
    class WeatherStatusTask {

    public:
        [[noreturn]] virtual void operator()(WeatherInfo *) const = 0;
    };
}


#endif //LCD_DHT11_WEATHERSTATUSTASK_H
