#include <iostream>
#include "PeripheralFactory.h"

using namespace std;


int main(int argc, char **argv) {
    const char *name;
    const Display::TextBasedDisplay *display = Factory::PeripheralFactory::build_display('\n');

    name = typeid(display).name();
    cout << "`TextBasedDisplay` Implementation: " << name << endl;

    const Sensors::WeatherStatus *weatherStatus = Factory::PeripheralFactory::build_sensor();
    Sensors::WeatherInfo weatherInfo{0, 0};
    name = typeid(weatherStatus).name();
    cout << "`WeatherStatus` Implementation: " << name << endl;

    weatherStatus->update_weather(&weatherInfo);

    cout << "T: " << weatherInfo.temperature << endl << "H: " << weatherInfo.humidity << endl;
}
