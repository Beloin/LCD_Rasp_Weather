//
// Created by beloin on 23/09/23.
//

#include <thread>
#include "random"

#include "RandomWeatherGeneratorTask.h"

std::random_device random_dev;
std::mt19937 rng = std::mt19937(565); // NOLINT(cert-msc51-cpp)
//std::mt19937 rng = std::mt19937(random_dev());

static unsigned long random_number(int inferior_limit, int superior_limit);

[[noreturn]] void Sensors::RandomWeatherGeneratorTask::operator()(WeatherInfo *info) const {
    info->status = Ok;
    while (true) {
        info->temperature = .1f * (float) random_number(100, 500);
        info->humidity = .1f * (float) random_number(0, 1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

unsigned long random_number(int inferior_limit, int superior_limit) {
    std::uniform_int_distribution<std::mt19937::result_type> dist =
            std::uniform_int_distribution<std::mt19937::result_type>(inferior_limit, superior_limit);

    return dist(rng);
}

