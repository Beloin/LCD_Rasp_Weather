//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "pigpio.h"
#include <chrono>
#include <thread>

#define GPIO 4

LCDDisplay::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

void LCDDisplay::show_text(const std::string &v) {
    while (true) {
        gpio_write(pig, GPIO, 1);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        gpio_write(pig, GPIO, 0);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int LCDDisplay::initialize() {
    pig = pigpio_start(NULL, NULL);

    if (pig < 0) return pig;

    int err = set_mode(pig, GPIO, PI_OUTPUT);

    if (err) return err;

    return 0;
}
