#include <cstdint>

class Bus{
    public:
        uint8_t readBus(uint16_t addr);
        void writeBus(uint16_t addr,uint8_t byte);
    private:
        //components
};