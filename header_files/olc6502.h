
// Forward-declare bus
class Bus;


class olc6502 {

    private:
        Bus *bus = nullptr;

        // Read 
        uint8_t read(uint16_t a);

        // Write
        void write(uint16_t a, uint8_t d);




    public:
        olc6502() {

        }

        ~olc6502() {

        }

        // Connect CPU to bus
        void ConnectBus(Bus *n) { bus = n; }
}