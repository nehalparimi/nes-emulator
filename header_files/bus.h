#pragma once
#include <cstdint>
#include <array>
#include "olc6502.h"


class Bus {

    public:

        Bus() {

        }

        ~Bus() {

        }

        /* Devices connected to the bus */

        // The CPU
        olc6502 cpu;

        // "Fake" RAM
        std::array<uint8_t, 64 * 1024> ram;

        /* Read and Write from CPU: */

        // Takes a 16-bit address (to write to) and 8-bit data (to write) as arguments
        void write(uint16_t address, uint8_t data);

        // Why is the return value an 8-bit integer?
        // Takes a 16-bit address to read from
        // The second flag can be ignored
        uint8_t read(uint16_t address, bool bReadOnly = false);


}