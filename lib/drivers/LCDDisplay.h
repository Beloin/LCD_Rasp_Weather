//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_LCDDISPLAY_H
#define LCD_DHT11_LCDDISPLAY_H


#include "drivers/TextBasedDisplay.h"

class LCDDisplay : public Display::TextBasedDisplay {
private:
    int pig;

public:
    explicit LCDDisplay(char lineBreak);

    void show_text(const std::string &v) override;

    int initialize() override;

};


#endif //LCD_DHT11_LCDDISPLAY_H
