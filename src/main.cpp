#include <iostream>
#include <vector>
#include <thread>
#include <sstream>
#include "PeripheralFactory.h"

using namespace std;

int main(int argc, char **argv) {
    const char *name;
    Display::TextBasedDisplay *display = Factory::PeripheralFactory::build_display('\n');
    display->initialize();

    name = typeid(*display).name();
    cout << "using \"" << name << "\" as TextBasedDisplay implementation." << endl;

    Sensors::WeatherStatusTask *pStatusTask = Factory::PeripheralFactory::build_sensor();
    Sensors::WeatherInfo weatherInfo{Sensors::Status::Imprecise, 0, 0};

    name = typeid(*pStatusTask).name();
    cout << "using \"" << name << "\" as WeatherStatusTask implementation." << endl;

    thread statusTask([&]() { (*pStatusTask)(&weatherInfo); });

    while (true) {
        std::stringstream a;
        a << "Temperature: " << weatherInfo.temperature
          << "\nHumidity: " << weatherInfo.humidity << "\n\n";
        display->show_text(a.str());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    statusTask.join();
}

