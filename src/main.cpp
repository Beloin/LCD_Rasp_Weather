#include <iostream>
#include <vector>
#include <thread>
#include <sstream>
#include "PeripheralFactory.h"

#include "spdlog/spdlog.h"

using namespace std;

[[noreturn]] int main(int argc, char **argv) {
#ifdef SPDLOG_DEBUG_ON
    spdlog::set_level(spdlog::level::debug);
#endif
    spdlog::info("spdlog version {}.{}.{} and level {}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR,
                 SPDLOG_VER_PATCH, to_string_view(spdlog::get_level()));

    const char *name;
    Display::TextBasedDisplay *display = Factory::PeripheralFactory::buildDisplay('\n');
    display->initialize();
    Sensors::WeatherStatusTask *pStatusTask = Factory::PeripheralFactory::buildSensor();
    Sensors::WeatherInfo weatherInfo{Sensors::Status::Imprecise, 0, 0};

    name = typeid(*display).name();
    spdlog::debug("using {} as TextBasedDisplay implementation", name);
    name = typeid(*pStatusTask).name();
    spdlog::debug("using {} as TextBasedDisplay implementation", name);

    thread statusTask([&]() { (*pStatusTask)(&weatherInfo); });

    while (true) {
        std::stringstream a;
        a << "Temperature: " << weatherInfo.temperature
          << "\nHumidity: " << weatherInfo.humidity;
        display->showText(a.str());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    statusTask.join();
}

