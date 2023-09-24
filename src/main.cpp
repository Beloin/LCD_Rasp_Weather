#include <iostream>
#include "DisplayBuilder.h"

using namespace std;


int main(int argc, char **argv) {
    Display::TextBasedDisplay *display = Display::DisplayBuilder::build('\n');
    Display::TextBasedDisplay &basedDisplay = *display;
    const char *name = typeid(basedDisplay).name();
    cout << "Hello World: " << name << endl;
}
