//
// Created by beloin on 04/08/23.
//

#ifndef LCD_DHT11_TEXTBASEDDISPLAY_H
#define LCD_DHT11_TEXTBASEDDISPLAY_H

#include <vector>
#include "string"
#include <sstream>

namespace Display {


    class TextBasedDisplay {

    public:
        explicit TextBasedDisplay(char line_break) {
            this->line_break = line_break;
        }

        virtual void showText(const std::string &v) = 0;

        virtual int initialize() = 0;

    protected:
        char line_break = '\n';

        [[nodiscard]] std::vector<std::string> parseString(const std::string &text) const {
            std::stringstream result;
            auto vector = std::vector<std::string>();

            for (auto c: text) {
                if (c != this->line_break) {
                    result << c;
                } else {
                    vector.push_back(result.str());
                    result.str(std::string());
                }
            }
            vector.push_back(result.str());

            return vector;
        }
    };

}

#endif //LCD_DHT11_TEXTBASEDDISPLAY_H
