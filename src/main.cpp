#include <iostream>
#include "DisplayBuilder.h"

using namespace std;


int main(int argc, char **argv) {
    TextBasedDisplay *display = DisplayBuilder::build('\n');
    TextBasedDisplay &basedDisplay = *display;
    const char *name = typeid(basedDisplay).name();
    cout << "Hello World: " << name << endl;
}
