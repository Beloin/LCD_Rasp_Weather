//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#if !ON_LINUX
#include "pigpio.h"
#endif

LCDDisplay::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

void LCDDisplay::show_text(const std::string &v) {
    // TODO: Create LCD implementation
}

void LCDDisplay::initialize() {

}

#if !ON_LINUX
#endif
