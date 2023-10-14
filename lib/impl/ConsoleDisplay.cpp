//
// Created by beloin on 06/08/23.
//

#include "ConsoleDisplay.h"
#include "iostream"

namespace Display {

    ConsoleDisplay::ConsoleDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

    void ConsoleDisplay::showText(const std::string &v) {
        const auto lines = parseString(v);

        for (auto &parsed: lines) {
            std::cout << parsed << std::endl;
        }
    }

    int ConsoleDisplay::initialize() {
        return 0;
    }

}

