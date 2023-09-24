//
// Created by beloin on 23/09/23.
//

#ifndef LCD_DHT11_WEATHERSTATUS_H
#define LCD_DHT11_WEATHERSTATUS_H

namespace Sensors {
    struct WeatherInfo {
        float temperature;
        float humidity;
    };

    class WeatherStatus {

        virtual void update_weather(WeatherInfo *) = 0;

    };
}


#endif //LCD_DHT11_WEATHERSTATUS_H
