#include "olc6502.h"

olc6502::olc6502() {

    using a = olc6502;



}

olc6502::~olc6502() {

}

// Calling the bus's read method
uint8_t olc6502::read(uint16_t a) {
    return bus->read(a, false);
}

// Calling the bus's write method
void olc6502::write(uint16_t a, uint8_t d) {
    bus->write(a, d);
}

void olc6502::clock() {
    if ()
}



