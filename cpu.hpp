#ifndef CPU_H
#define CPU_H

#include "utils.hpp"
#include "address.hpp"

struct CPU {
    using Byte = std::uint8_t;

    struct Word {
        Byte data[6];
    };

    Address PC;   //program counter
    Address SP;   //stack pointer
    Word SR;   //status register 

    //flags 
    unsigned OF : 1; //overflow flag
    unsigned SF : 1; //sign flag
    unsigned ZF : 1; //zero flag
    unsigned CF : 1; //carry flag

    //resets everything
    void Reset(){
        Address stackStart = {10, 0};
        Address programCounterStart = {5, 0};

        PC = programCounterStart;
        SP = stackStart;
        OF = SF = ZF = CF = 0;
    }
};

#endif