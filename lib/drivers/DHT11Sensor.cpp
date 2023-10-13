//
// Created by beloin on 24/09/23.
//

#include "iostream"
#include <chrono>
#include <thread>
#include "mutex"

#include "DHT11Sensor.h"
#include "pigpio.h"
#include "spdlog/spdlog.h"

#define DHT11_GPIO 6
#define TOTAL_BITS 40

using namespace std;
using namespace Sensors;

static int initialize();

static void gpio_change_sr(int gpio, int level, uint32_t tick);

int start_tick;
int bit_count;
uint8_t sensor_data[5];

void Sensors::DHT11Sensor::operator()(Sensors::WeatherInfo *weatherInfo) const {
    if (initialize()) {
        weatherInfo->status = Status::Error;
        spdlog::debug("error while initializing DHT11 Sensor");
    }

    gpioSetPullUpDown(DHT11_GPIO, PI_PUD_UP);
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Wait for DHT11 is available again
        spdlog::debug("Reading from DHT11");

        bit_count = -3; // Three first low data will be Communication bits
        start_tick = gpioTick();
        gpioSetMode(DHT11_GPIO, PI_OUTPUT);
        gpioWrite(DHT11_GPIO, 1);
        gpioDelay(50000);

        gpioWrite(DHT11_GPIO, 0);
        gpioDelay(18000);
        gpioWrite(DHT11_GPIO, 1);

        gpioDelay(20);
        gpioSetMode(DHT11_GPIO, PI_INPUT);

        // This waits for all data transmission.
        gpioDelay(50000);

        bool has40bits = bit_count == 40;
        uint8_t checksum = (sensor_data[0] + sensor_data[1] + sensor_data[2] + sensor_data[3]) & 0xFF;
        if (has40bits && (sensor_data[4] == checksum)) {
            float tempC;
            float humidity;

            humidity = sensor_data[0] + sensor_data[1] / 10.0f;
            tempC = sensor_data[2] + sensor_data[3] / 10.0f;

            weatherInfo->status = Status::Ok;
            weatherInfo->humidity = humidity;
            weatherInfo->temperature = tempC;
        } else {
            weatherInfo->status = Status::Error;
        }

    }
}

static std::once_flag flag;

int initialize() {
    spdlog::info("initializing DHT11");
    static int err = 0;

    std::call_once(flag, [&]() {
        err = gpioSetAlertFunc(DHT11_GPIO, gpio_change_sr);
    });

    return err;
}

static void gpio_change_sr(int gpio, int level, uint32_t tick) {
    if (level == 0) {
        int duration = tick - start_tick;
        start_tick = tick;
        if (++bit_count > 0) {
            sensor_data[(bit_count - 1) / 8] <<= 1;
            // In datasheet 50us + 70us == 1
            // In datasheet 50us + 26-28us == 0
            sensor_data[(bit_count - 1) / 8] |= (duration > 100 ? 1 : 0);
        }
    }
}
