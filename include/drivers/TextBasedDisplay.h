//
// Created by beloin on 04/08/23.
//

#ifndef LCD_DHT11_TEXTBASEDDISPLAY_H
#define LCD_DHT11_TEXTBASEDDISPLAY_H

#include "string"

class TextBasedDisplay {

public:
    virtual void show_text(const std::string &v) = 0;

    explicit TextBasedDisplay(char line_break) {
        this->line_break = line_break;
    }

    virtual int initialize() = 0;

protected:
    char line_break = '\n';
};


#endif //LCD_DHT11_TEXTBASEDDISPLAY_H
