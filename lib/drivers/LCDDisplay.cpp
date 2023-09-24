//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "pigpio.h"
#include <chrono>
#include <thread>

#define GPIO 4

using Driver::LCDDisplay;

LCDDisplay::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

void LCDDisplay::show_text(const std::string &v) {
    while (true) {
        gpioWrite(GPIO, 1);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        gpioWrite(GPIO, 0);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int LCDDisplay::initialize() {
    pig = gpioInitialise();

    if (pig < 0) return pig;

    int err = gpioSetMode(GPIO, PI_OUTPUT);

    if (err) return err;

    return 0;
}

// TODO: Create a way to destroy everything
LCDDisplay::~LCDDisplay() {}