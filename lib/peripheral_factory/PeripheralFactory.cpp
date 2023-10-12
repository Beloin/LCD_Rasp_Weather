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

    int PeripheralFactory::Initialize() {
        return 0;
    }
}

#else

#include "ConsoleDisplay.h"
#include "LCDDisplay.h"
#include "DHT11Sensor.h"
#include "RandomWeatherGeneratorTask.h"
#include <mutex>

namespace Factory {

    Display::TextBasedDisplay *PeripheralFactory::buildDisplay(char line_separator) {
        return new Display::LCDDisplay('\n');
    }

    Sensors::WeatherStatusTask *PeripheralFactory::buildSensor() {
        return new Sensors::DHT11Sensor();
    }

    static std::once_flag flag;

    int PeripheralFactory::Initialize() {
        static int err = 0;
        std::call_once(flag, [&]() {
            err = gpioInitialise();

            if (err == PI_INIT_FAILED) {
                return err;
            }
        });

        return err;
    }
}

#endif

