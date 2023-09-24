//
// Created by beloin on 06/08/23.
//

#include "PeripheralFactory.h"


#if ON_LINUX

#include "ConsoleDisplay.h"
#include "RandomWeatherGeneratorTask.h"

namespace Factory {

    Display::TextBasedDisplay *PeripheralFactory::build_display(char line_separator) {
        return new Display::ConsoleDisplay('\n');
    }

    Sensors::WeatherStatusTask *PeripheralFactory::build_sensor() {
        return new Sensors::RandomWeatherGeneratorTask();
    }
}

#else

#include "LCDDisplay.h"
#include "RandomWeatherGeneratorTask.h"

namespace Factory {

    // TODO: For now we will be using ConsoleDisplay because we need to add pins to LCD
    Display::TextBasedDisplay *PeripheralFactory::build(char line_separator) {
        return new Display::ConsoleDisplay('\n');
    }

    Sensors::WeatherStatusTask *PeripheralFactory::build_sensor() {
        return new Sensors::RandomWeatherGeneratorTask();
    }
}

#endif

