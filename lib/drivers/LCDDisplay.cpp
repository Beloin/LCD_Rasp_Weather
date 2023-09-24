//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "mutex"
#include "pigpio.h"
#include <chrono>
#include <thread>

#define GPIO 4

using Display::LCDDisplay;

Display::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

void LCDDisplay::show_text(const std::string &v) {
    while (true) {
        gpioWrite(GPIO, 1);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        gpioWrite(GPIO, 0);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

std::once_flag flag;

int LCDDisplay::initialize() {
    static int err = 0;
    std::call_once(flag, [&]() {
        pig = gpioInitialise();

        if (pig < 0) return pig;

        err = gpioSetMode(GPIO, PI_OUTPUT);
    });

    return err;
}

// TODO: Create a way to destroy everything
LCDDisplay::~LCDDisplay() {}