#include <iostream>
#include <vector>
#include <thread>
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
    const Display::TextBasedDisplay *display = Factory::PeripheralFactory::build_display('\n');

    name = typeid(*display).name();
    cout << "`TextBasedDisplay` Implementation: " << name << endl;

    const Sensors::WeatherStatusTask *pStatusTask = Factory::PeripheralFactory::build_sensor();
    Sensors::WeatherInfo weatherInfo{Sensors::Status::Imprecise, 0, 0};

    name = typeid(*pStatusTask).name();
    cout << "`WeatherStatusTask` Implementation: " << name << endl;

    thread statusTask([&]() { (*pStatusTask)(&weatherInfo); });
    statusTask.join();
}

