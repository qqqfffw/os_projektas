#ifndef CPU_H
#define CPU_H

#include "utils.hpp"
#include "address.hpp"

struct CPU {
    using Byte = std::uint8_t;

    //swap reikalingas kaip file. Bendra realios masinos atmintis kad paleisti bent viena vm, o antra galima i swap.
    //Is viso rm atminties: 256 * 6 (supervizorine) + 256 * 6 * 257 * 1 (is vieno nes tik tiek tilps vm jei 2 tai * 2 ir t,t,)
    //swap atminties tarkim telpa 100 vm nes failas. 
    // puslapiu lenteles pats pirmas bit rodo ar swape yra ar rame. Tarkim 0 swape o 1 ram. Kanalu irenginys turi moketi keitineti tarp swap ir vm.
    //paleidziam rm su 1 pradedam program 2 exit
    // spaudziam 1 ir kuriam vm su pavadinimu turi nueiti i kieta diska su LOOP_01 ir ji perkopijuoti i supervizorine
    //pravaliduoti ar viskas yra gerai. Kai perkeliam i supervizorine issikiriam viena laisva bloka ptr rodo i ji bloka.
    //Issiskiriam 256
    //Supervizorinei perkopijuoti 256.
    //tikrina ar interuptas ir kai program interrupt ivyksta issokam is while ir gryztam i pradini meniu. while(true) break; gryzta.
    //interrupt bendrauja su kazkokiu kitu irenginiu.
    //scan iskart pavercia i hex. prisidedi intterupt kuris moka isvesti skaiciu hex i sk.
    //visos programos i viena hdd.txt

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