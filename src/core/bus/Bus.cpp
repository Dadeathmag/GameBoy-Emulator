#include "Bus.hpp"

uint8_t Bus::read(uint16_t addr){
    switch(mapper(addr)){
        case Component::ROM0:
        case Component::ROMX:
            break;
        default:
            return 0xFF;
    };
}

void Bus::write(uint16_t addr,uint8_t byte){
    switch(mapper(addr)){};
}

Component Bus::mapper(uint16_t addr){
    switch(addr>>12){
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
            //Rom bank 0
            return Component::ROM0;
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            //switchable Rom bank 1 to N (managed by cartridge)
            return Component::ROMX; 
        case 0x8:
        case 0x9:
            //Vram (DMG:has only bank,CGB:can switch BtW 0/1)
            return Component::VRAM;
        case 0xA:
        case 0xB:
            //External Ram from cartridge(switchable)
            return Component::CART_RAM;
        case 0xC:
            //Work Ram bank 0   (Wram Partition only applicable to CGB) 
            return Component::WRAM; 
        case 0xD:
            //Work Ram bank 1-7 (Wram Partition only applicable to CGB)
            return Component::WRAM;
        case 0xE://upto FDFF
            //Echo RAM (mirror of C000–DDFF) prohibited
            return Component::ECHO_RAM;
        case 0xF:
            if (addr <= 0xFDFF){
                // Echo RAM (mirror of C000–DDFF) prohibited
                return Component::ECHO_RAM;
            }else if (addr <= 0xFE9F){
                // OAM 
                return Component::OAM;
            }else if (addr <= 0xFEFF){
                // Unusable
                return Component::INVALID;
            }else if (addr <= 0xFF7F){
                // IO Registers 
                return Component::IOreg;
            }else if (addr <= 0xFFFE){
                // HRAM
                return Component::HRAM;
            }else{
                // IE Register
                return Component::IEreg;
            }
            break;
        default:
            //invalid address
            return Component::INVALID;
            break;
    }
}