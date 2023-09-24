//
// Created by beloin on 06/08/23.
//

#ifndef LCD_DHT11_DISPLAYBUILDER_H
#define LCD_DHT11_DISPLAYBUILDER_H


#include "drivers/TextBasedDisplay.h"

namespace Display {

    class DisplayBuilder {
    public:
        static TextBasedDisplay *build(char line_separator);
    };

}


#endif //LCD_DHT11_DISPLAYBUILDER_H
