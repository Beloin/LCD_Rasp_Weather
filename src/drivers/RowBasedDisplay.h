//
// Created by beloin on 04/08/23.
//

#ifndef LCD_DHT11_ROWBASEDDISPLAY_H
#define LCD_DHT11_ROWBASEDDISPLAY_H

#include "string"

class RowBasedDisplay {

public:
    virtual void show_text(int row, std::string const *v) = 0;
};


#endif //LCD_DHT11_ROWBASEDDISPLAY_H
