//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_CONSOLEDISPLAY_H
#define LCD_DHT11_CONSOLEDISPLAY_H


#include "drivers/TextBasedDisplay.h"

class ConsoleDisplay : public TextBasedDisplay  {
public:
    explicit ConsoleDisplay(char lineBreak);

    void show_text(const std::string &v) override;
    int initialize();

};


#endif //LCD_DHT11_CONSOLEDISPLAY_H
