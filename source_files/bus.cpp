#include "bus.h"

// Default constructor
Bus::Bus() {
    // Clears RAM contents when initialized
    for(auto &i : ram) i = 0x00;

    // Connect CPU to bus
    cpu.connectBus(this);
}

// Kamehameha
Bus::~Bus() {

}

// Writing to memory
    // Using a safeguard to make sure we don't go out of bounds
void Bus::write(uint16_t address, uint8_t data) {

    if (address >= 0x0000 && address <= 0xFFFF)
        ram[addr] = data;
}

// Reading from an address
uint8_t Bus::read(uint16_t address, bool bReadOnly) {

    if (address >= 0x0000 && address <= 0xFFFF)
        return ram[addr];
    
    // If outside range
    return 0x00;
}







