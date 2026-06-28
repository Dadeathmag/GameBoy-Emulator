#include <cstdint>
#include <vector>

class Cartridge{
    public:
        bool loadROM(const char* filename);
        uint8_t read(uint16_t addr);
        void write(uint16_t addr, uint8_t byte);
    private:
        std::vector<uint8_t> ROM;
};