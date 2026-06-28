#include <cstdint>

enum class Component:uint8_t{
    ROM0,
    ROMX,
    VRAM,
    CART_RAM,
    WRAM,
    //SWRAM,
    ECHO_RAM,
    OAM,
    IOreg,
    HRAM,
    IEreg,
    INVALID=0xFF,
};

class Bus{
    public:
        uint8_t read(uint16_t addr);
        void write(uint16_t addr,uint8_t byte);
    private:
        Component mapper(uint16_t addr);
        //components
};