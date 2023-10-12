//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "mutex"
#include "pigpio.h"
#include <sstream>
#include <thread>
#include "vector"
#include "spdlog/spdlog.h"

#define LCD_RS  4
#define LCD_E   5
#define LCD_D4  27
#define LCD_D5  22
#define LCD_D6  23
#define LCD_D7  24

#define TO_MS 1000

using Display::LCDDisplay;

const std::vector<std::string> *parseString(std::string &text, char line_break);

void send4Bits(char data, char rs);

void sendCommand(char command);

void putCursor(char row, char column);

void sendData(char data);

void initLcd();

LCDDisplay::LCDDisplay(char lineBreak) : TextBasedDisplay(lineBreak) {}

char current_col = 0, current_row = 0;

void LCDDisplay::showText(const std::string &v) {
    auto lines = parseString(v);
    int i = 0;
    for (auto &parsed: *lines) {
        spdlog::debug("ParsedString Line[{}]->{}", i, parsed);

        putCursor(i, 0);
        for (auto &c: parsed) {
            sendData(c);
        }

        i++;
    }

    delete lines;
}

static std::once_flag flag;

int LCDDisplay::initialize() {
    static int err = 0;
    std::call_once(flag, [&]() {
        err = gpioSetMode(LCD_RS, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_RS);
            return err;
        }

        err = gpioSetMode(LCD_E, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_E);
            return err;
        }

        err = gpioSetMode(LCD_D4, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_D4);
            return err;
        }
        err = gpioSetMode(LCD_D5, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_D5);
            return err;
        }
        err = gpioSetMode(LCD_D6, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_D6);
            return err;
        }
        err = gpioSetMode(LCD_D7, PI_OUTPUT);
        if (err) {
            spdlog::info("err with {} GPIO", LCD_D7);
            return err;
        }

        initLcd();
    });

    return err;
}

// TODO: Create a way to destroy everything
LCDDisplay::~LCDDisplay() {}

const std::vector<std::string> *LCDDisplay::parseString(const std::string &text) {
    std::stringstream result;
    std::vector<std::string> *vector = new std::vector<std::string>();

    for (auto &c: text) {
        if (c != this->line_break) {
            result << c;
        } else {
            vector->push_back(result.str());
            result.str(std::string());
        }
    }
    vector->push_back(result.str());

    return vector;
}

void initLcd() {
    spdlog::info("initializing LCD");

    gpioDelay(50 * TO_MS);
    sendCommand(0x33);
    sendCommand(0x32);
    sendCommand(0x06);
    sendCommand(0x0C);
    sendCommand(0x28);
    sendCommand(0x01);
    gpioDelay(50 * TO_MS);
}

void putCursor(char row, char column) {
    switch (row) {
        case 0:
            column |= 0x80;
            break;
        case 1:
            column |= 0xC0;
            break;
    }

    sendCommand(column);
}

void sendCommand(char command) {
    send4Bits((command >> 4) & 0xf, 0);
    send4Bits((command) & 0xf, 0);
}

void sendData(char data) {
    send4Bits((data >> 4) & 0xf, 1);
    send4Bits((data) & 0xf, 1);
}

void send4Bits(char data, char rs) {
    gpioWrite(LCD_RS, rs);  // rs = 1 for data, rs=0 for command
    gpioWrite(LCD_D7, ((data >> 3) & 0x1));
    gpioWrite(LCD_D6, ((data >> 2) & 0x1));
    gpioWrite(LCD_D5, ((data >> 1) & 0x1));
    gpioWrite(LCD_D4, ((data >> 0) & 0x1));

    gpioDelay(100); // TODO: This can use time interruptions in order to make it more efficient
    gpioWrite(LCD_E, 1);
    gpioDelay(100);
    gpioWrite(LCD_E, 0);
    gpioDelay(100);
}