//
// Created by beloin on 06/08/23.
//

#include "PeripheralFactory.h"


#if ON_LINUX

#include "ConsoleDisplay.h"
#include "RandomWeatherGenerator.h"

namespace Factory {

    Display::TextBasedDisplay *PeripheralFactory::build_display(char line_separator) {
        return new Display::ConsoleDisplay('\n');
    }

    Sensors::WeatherStatus *PeripheralFactory::build_sensor() {
        return new Sensors::RandomWeatherGenerator();
    }
}

#else
#include "LCDDisplay.h"

namespace Display {

    Display::TextBasedDisplay *PeripheralFactory::build(char line_separator) {
        return new LCDDisplay('\n');
    }

}

#endif

