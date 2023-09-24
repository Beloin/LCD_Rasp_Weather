//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_PERIPHERALFACTORY_H
#define LCD_DHT11_PERIPHERALFACTORY_H


#include "drivers/TextBasedDisplay.h"

namespace Factory {

    class PeripheralFactory {
    public:
        static Display::TextBasedDisplay *build(char line_separator);
    };

}


#endif //LCD_DHT11_PERIPHERALFACTORY_H
