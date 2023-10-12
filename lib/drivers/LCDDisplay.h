//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_LCDDISPLAY_H
#define LCD_DHT11_LCDDISPLAY_H


#include "drivers/TextBasedDisplay.h"

namespace Display {

    class LCDDisplay : public TextBasedDisplay {
    private:
        int pig;

    public:
        explicit LCDDisplay(char lineBreak);

        void showText(const std::string &v) override;

        int initialize() override;

        ~LCDDisplay();

    };

}


#endif //LCD_DHT11_LCDDISPLAY_H
