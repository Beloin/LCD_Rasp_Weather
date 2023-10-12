//
// Created by beloin on 06/08/23.
//

#include "LCDDisplay.h"

#include "mutex"
#include "pigpio.h"
#include <sstream>
#include <thread>
#include "vector"

#define LCD_RS  4
#define LCD_E   5
#define LCD_D4  27
#define LCD_D5  22
#define LCD_D6  23
#define LCD_D7  24

// Define some device constants
#define LCD_WIDTH 16    // Maximum characters per line
#define LCD_CHR true
#define LCD_CMD false
#define LCD_LINE_1 0x80 // LCD RAM address for the 1st line
#define LCD_LINE_2 0xC0 // LCD RAM address for the 2nd line

#define E_PULSE 0.0005
#define E_DELAY 0.0005

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
    sendData('J');
}

std::once_flag flag;

int LCDDisplay::initialize() {
    static int err = 0;
    std::call_once(flag, [&]() {
        pig = gpioInitialise(); // TODO: Call this elsewhere

        if (pig < 0) {
            err = pig;
            return pig;
        }

        err = gpioSetMode(LCD_RS, PI_OUTPUT);
        err = gpioSetMode(LCD_E, PI_OUTPUT);
        err = gpioSetMode(LCD_D4, PI_OUTPUT);
        err = gpioSetMode(LCD_D5, PI_OUTPUT);
        err = gpioSetMode(LCD_D6, PI_OUTPUT);
        err = gpioSetMode(LCD_D7, PI_OUTPUT);

        initLcd();
    });

    return err;
}

// TODO: Create a way to destroy everything
LCDDisplay::~LCDDisplay() {}

const std::vector<std::string> *parseString(std::string &text, char line_break) {
    std::stringstream result;
    std::vector<std::string> *vector = new std::vector<std::string>();

    for (auto &c: text) {
        if (c != line_break) {
            result << c;
        } else {
            vector->push_back(result.str());
            result.str(std::string());
        }
    }

    return vector;
}

void initLcd() {
    // 4 Bit configuration
    gpioDelay(50 * TO_MS);
    sendCommand(0x30);
    gpioDelay(5 * TO_MS);
    sendCommand(0x30);

    gpioDelay(150);
    sendCommand(0x30);
    gpioDelay(10 * TO_MS);
    sendCommand(0x20);
    gpioDelay(10 * TO_MS);

    sendCommand(0x28);
    gpioDelay(150);
    sendCommand(0x08);
    gpioDelay(150);
    sendCommand(0x01);
    gpioDelay(150);
    gpioDelay(150);
    sendCommand(0x06);
    gpioDelay(150);
    sendCommand(0x0C);
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

    gpioWrite(LCD_E, 1);
    gpioDelay(50); // TODO: This can use time interruptions in order to make it more efficient
    gpioWrite(LCD_E, 0);
    gpioDelay(50);
}