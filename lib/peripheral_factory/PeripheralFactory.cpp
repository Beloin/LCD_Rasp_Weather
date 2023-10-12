//
// Created by beloin on 06/08/23.
//

#include "PeripheralFactory.h"


#if ON_LINUX

#include "ConsoleDisplay.h"
#include "RandomWeatherGeneratorTask.h"

namespace Factory {

    Display::TextBasedDisplay *PeripheralFactory::buildDisplay(char line_separator) {
        return new Display::ConsoleDisplay('\n');
    }

    Sensors::WeatherStatusTask *PeripheralFactory::buildSensor() {
        return new Sensors::RandomWeatherGeneratorTask();
    }
}

#else

#include "ConsoleDisplay.h"
#include "LCDDisplay.h"
#include "DHT11Sensor.h"
#include "RandomWeatherGeneratorTask.h"

namespace Factory {

    // TODO: For now we will be using ConsoleDisplay because we need to add pins to LCD
    Display::TextBasedDisplay *PeripheralFactory::buildDisplay(char line_separator) {
        return new Display::ConsoleDisplay('\n');
    }

    Sensors::WeatherStatusTask *PeripheralFactory::buildSensor() {
        return new Sensors::DHT11Sensor();
    }
}

#endif

