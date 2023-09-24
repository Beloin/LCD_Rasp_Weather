#include <iostream>
#include <vector>
#include <thread>
#include <sstream>
#include "PeripheralFactory.h"

using namespace std;

int main(int argc, char **argv) {
    vector<int> int_vector = vector<int>();
    int_vector.push_back(12);
    int_vector.push_back(14);

    for (vector<int>::iterator it = int_vector.begin(); it != int_vector.end(); it++) {
        int &i = *it; //  Same as: int *i = &*it
        cout << i << endl;
        i++;
    }

    for (vector<int>::iterator it = int_vector.begin(); it != int_vector.end(); it++) {
        int &i = *it;
        cout << i << endl;
    }

    const char *name;
    Display::TextBasedDisplay *display = Factory::PeripheralFactory::build_display('\n');
    display->initialize();

    name = typeid(*display).name();
    cout << "`TextBasedDisplay` Implementation: " << name << endl;

    Sensors::WeatherStatusTask *pStatusTask = Factory::PeripheralFactory::build_sensor();
    Sensors::WeatherInfo weatherInfo{Sensors::Status::Imprecise, 0, 0};

    name = typeid(*pStatusTask).name();
    cout << "`WeatherStatusTask` Implementation: " << name << endl;

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

