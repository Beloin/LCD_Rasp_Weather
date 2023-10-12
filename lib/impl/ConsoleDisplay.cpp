//
// Created by beloin on 06/08/23.
//

#include "ConsoleDisplay.h"
#include "iostream"

namespace Display {

    ConsoleDisplay::ConsoleDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

    void ConsoleDisplay::showText(const std::string &v) {
        // Replace any special line_break char
        std::string from = std::string(1, line_break);
        std::string to = "\n";
        size_t pos = 0;
        while ((pos = v.find(from, pos)) != std::string::npos) {
//            v.replace(); // TODO: This does not work... Why?
//            v.replace(pos, from.length(), to);
            pos += to.length();
        }
        std::cout << v << "\n";
    }

    int ConsoleDisplay::initialize() {
        return 0;
    }
}

