
// Forward-declare bus
class Bus;


class olc6502 {

    private:
        Bus *bus = nullptr;

        // Read 
        uint8_t read(uint16_t a);

        // Write
        void write(uint16_t a, uint8_t d);

        // Get and set flags; for convenience
        uint8_t GetFlag(FLAGS6502 f);
        void SetFlag(FLAGS6502f, bool value);

        




    public:
        olc6502() {

        }

        ~olc6502() {

        }

        enum FLAGS6502 {
            C = (1 << 0),   // CARRY BIT
            Z = (1 << 1),   // ZERO
            I = (1 << 2),   // DISABLE INTERRUPTS
            D = (1 << 3),   // DECIMAL MODE
            B = (1 << 4),   // BREAK
            U = (1 << 5),   // UNUSED
            V = (1 << 6),   // OVERFLOW
            N = (1 << 7),   // NEGATIVE
        };

        // Defining the registers:
        uint8_t a = 0x00;
        uint8_t x = 0x00;
        uint8_t y = 0x00;
        uint8_t stk_ptr = 0x00;
        uint16_t pc = 0x0000;
        uint8_t stat_reg = 0x00;

        // Connect CPU to bus
        void ConnectBus(Bus *n) { bus = n; }

        // Functions central to the operation of the CPU
        void clock();   // for clock ticks
        void reset();   // to reset?
        void irq();     // interruprs
        void nmi();     // non-maskable interrupts

        // Internal helper functions:
        uint8_t fetch();    // fetch data from address
        uint8_t fetched = 0x00;     // variable to store fetched data

        uint16_t addr_abs = 0x0000;
        uint16_t addr_rel = 0x0000;
        uint8_t opcode = 0x00;
        uint8_t cycles = 0;     // cycles left in duration of instruction

        // Addressing Modes: Each is a function (in this implementation)
        uint8_t IMP();  uint8_t IMM();
        uint8_t ZP0();  uint8_t ZPX();
        uint8_t ZPY();  uint8_t REL();
        uint8_t ABS();  uint8_t ABX();
        uint8_t ABY();  uint8_t IND();
        uint8_t IZX(;   uint8_t IZY();

        // Opcodes

        uint8_t ADC();
        uint8_t AND();
        uint8_t ASL();
        uint8_t BCC();
        uint8_t BCS();
        uint8_t BEQ();
        uint8_t BIT();
        uint8_t BMI();
        uint8_t BNE();
        uint8_t BPL();
        uint8_t BRK();
        uint8_t BVC();
        uint8_t BVS();
        uint8_t CLC();
        uint8_t CLD();
        uint8_t CLI();
        uint8_t CLV();
        uint8_t CMP();
        uint8_t CPX();
        uint8_t CPY();
        uint8_t DEC();
        uint8_t DEX();
        uint8_t DEY();
        uint8_t EOR();
        uint8_t INC();
        uint8_t INX();
        uint8_t INY();
        uint8_t JMP();
        uint8_t JSR();
        uint8_t LDA();
        uint8_t LDX();
        uint8_t LDY();
        uint8_t LSR();
        uint8_t NOP();
        uint8_t ORA();
        uint8_t PHA();
        uint8_t PHP();
        uint8_t PLA();
        uint8_t PLP();
        uint8_t ROL();
        uint8_t ROR();
        uint8_t RTI();
        uint8_t RTS();
        uint8_t SBC();
        uint8_t SEC();
        uint8_t SED();
        uint8_t SEI();
        uint8_t STA();
        uint8_t STX();
        uint8_t STY();
        uint8_t TAX();
        uint8_t TAY();
        uint8_t TSX();
        uint8_t TXA();
        uint8_t TXS();
        uint8_t TYA();

        uint8_t XXX();

        struct INSTRUCTION {
            std::string name;
            uint8_t(olc6502::*operate)(void) = nullptr;     // function pointer to the operation to be performed
            uint8_t(olc6502::*address)(void) = nullptr;     // function pointer to the addressing mode
            uint8_t cycles = 0;
        }
        
        std::vector<INSTRUCTION> lookup;

}