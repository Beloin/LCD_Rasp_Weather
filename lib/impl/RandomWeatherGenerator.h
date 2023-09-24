//
// Created by beloin on 23/09/23.
//

#ifndef LCD_DHT11_RANDOMWEATHERGENERATOR_H
#define LCD_DHT11_RANDOMWEATHERGENERATOR_H

#include "drivers/WeatherStatus.h"

using Sensors::WeatherStatus;

class RandomWeatherGenerator : WeatherStatus {

    void update_weather(Sensors::WeatherInfo *info) override;

};


#endif //LCD_DHT11_RANDOMWEATHERGENERATOR_H
