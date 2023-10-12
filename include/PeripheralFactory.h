//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_PERIPHERALFACTORY_H
#define LCD_DHT11_PERIPHERALFACTORY_H


#include "drivers/TextBasedDisplay.h"
#include "drivers/WeatherStatusTask.h"

namespace Factory {

    class PeripheralFactory {

    public:
        static Display::TextBasedDisplay *buildDisplay(char line_separator);
        static Sensors::WeatherStatusTask *buildSensor();
    };


}


#endif //LCD_DHT11_PERIPHERALFACTORY_H
