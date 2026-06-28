#include "Bus.hpp"

uint8_t Bus::readBus(uint16_t addr){
    
    switch(addr>>12){
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
            //Rom bank 0
            break;
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            //switchable Rom bank 1 to N (managed by cartridge) 
            break;
        case 0x8:
        case 0x9:
            //Vram (DMG:has only bank,CGB:can switch BtW 0/1)
            break;
        case 0xA:
        case 0xB:
            //External Ram from cartridge(switchable)
            break;
        case 0xC:
            //Work Ram bank 0   (Wram Partition only applicable to CGB)  
        case 0xD:
            //Work Ram bank 1-7 (Wram Partition only applicable to CGB)
            break;
        case 0xE://upto FDFF
            //Echo RAM (mirror of C000–DDFF) prohibited
            break;
        case 0xF:
            if (addr <= 0xFDFF){
                // Echo RAM (mirror of C000–DDFF) prohibited
            }else if (addr <= 0xFE9F){
                // OAM 
            }else if (addr <= 0xFEFF){
                // Unusable
            }else if (addr <= 0xFF7F){
                // IO Registers 
            }else if (addr <= 0xFFFE){
                // HRAM
            }else{
                // IE Register
            }
            break;
        default:
            //invalid address
            break;
    }
}

void Bus::writeBus(uint16_t addr,uint8_t byte){
    
    switch(addr>>12){
        case 0x0:
        case 0x1:
        case 0x2:
        case 0x3:
            //Rom bank 0
            break;
        case 0x4:
        case 0x5:
        case 0x6:
        case 0x7:
            //switchable Rom bank 1 to N (managed by cartridge) 
            break;
        case 0x8:
        case 0x9:
            //Vram (DMG:has only bank,CGB:can switch BtW 0/1)
            break;
        case 0xA:
        case 0xB:
            //External Ram from cartridge(switchable)
            break;
        case 0xC:
            //Work Ram bank 0   (Wram Partition only applicable to CGB)  
        case 0xD:
            //Work Ram bank 1-7 (Wram Partition only applicable to CGB)
            break;
        case 0xE://upto FDFF
            //Echo RAM (mirror of C000–DDFF) prohibited
            break;
        case 0xF:
            if (addr <= 0xFDFF){
                // Echo RAM (mirror of C000–DDFF) prohibited
            }else if (addr <= 0xFE9F){
                // OAM 
            }else if (addr <= 0xFEFF){
                // Unusable
            }else if (addr <= 0xFF7F){
                // IO Registers 
            }else if (addr <= 0xFFFE){
                // HRAM
            }else{
                // IE Register
            }
            break;
        default:
            //invalid address
            break;
    }
}