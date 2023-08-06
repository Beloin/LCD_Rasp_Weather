//
// Created by beloin on 04/08/23.
//

#ifndef LCD_DHT11_TEXTBASEDDISPLAY_H
#define LCD_DHT11_TEXTBASEDDISPLAY_H

#include "string"

// TODO: PUT ME INSIDE LIB FILES AND IMPLEMENT AS A EXTERNAL RESOURCE!!!!
class TextBasedDisplay {

public:
    virtual void show_text(std::string const *v) = 0;

    explicit TextBasedDisplay(char line_break) {

    }

protected:
    char line_break = '\n';
};


#endif //LCD_DHT11_TEXTBASEDDISPLAY_H
