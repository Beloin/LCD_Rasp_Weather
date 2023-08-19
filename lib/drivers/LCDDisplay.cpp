//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "pigpio.h"

LCDDisplay::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

void LCDDisplay::show_text(const std::string &v) {
    // TODO: Create LCD implementation
}

void LCDDisplay::initialize() {

}
