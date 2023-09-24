//
// Created by beloin on 23/09/23.
//

#include "RandomWeatherGenerator.h"

#include "random"

std::random_device random_dev;
std::mt19937 rng = std::mt19937(565); // NOLINT(cert-msc51-cpp)
//std::mt19937 rng = std::mt19937(random_dev());

unsigned long random_number(int inferior_limit, int superior_limit);

void RandomWeatherGenerator::update_weather(Sensors::WeatherInfo *const info) {
    info->temperature = .1f * (float) random_number(100, 500);
    info->humidity = .1f * (float) random_number(0, 1000);
}

unsigned long random_number(int inferior_limit, int superior_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist =
            std::uniform_int_distribution<std::mt19937::result_type>(inferior_limit, superior_limit);

    return dist(rng);
}



