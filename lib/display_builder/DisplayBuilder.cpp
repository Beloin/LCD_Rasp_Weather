//
// Created by beloin on 06/08/23.
//

#include "DisplayBuilder.h"


#if ON_LINUX

#include "ConsoleDisplay.h"

namespace Display {

    TextBasedDisplay *DisplayBuilder::build(char line_separator) {
        return new ConsoleDisplay('\n');
    }
}

#else
#include "LCDDisplay.h"

namespace Display {

    TextBasedDisplay *DisplayBuilder::build(char line_separator) {
        return new LCDDisplay('\n');
    }

}

#endif

