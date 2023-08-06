//
// Created by beloin on 06/08/23.
//

#include "ConsoleDisplay.h"
#include "LCDDisplay.h"
#include "DisplayBuilder.h"

TextBasedDisplay* DisplayBuilder::build(char line_separator) {
#if ON_LINUX
    return new ConsoleDisplay('\n');
#else
    return new LCDDisplay('\n'); // TODO: Return implementation depending on CPU (rasp or linux)
#endif
}
