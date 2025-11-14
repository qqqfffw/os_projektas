#include "commands.hpp"
#include "utils.hpp"
#include "cpu.hpp"

//for now works only with one block 5
void runProgram(CPU &cpu){

    Address pc = cpu.PC; //code segment start

    while(true){

        std::string codeSeg = getBlock(pc.block, VM_MEMORY_FILE);
        int start = 3 + pc.offset * 7;

        //when no word has 6 end
        if (start + 6 > codeSeg.size()) {
            break;
        }

        std::string codeWord = getWord(codeSeg, pc.offset);

        if(codeWord.compare(0, 2, "PU") == 0){
            PUXXYY(codeWord);
        }else if(codeWord.compare(0, 2, "JD") == 0){
            pc = JDXXYY(pc);
        }else if(codeWord.compare(0, 7, "DEDUCT") == 0){
            //DEDUCT();
        }else if(codeWord.compare(0, 7, "SUSPND") == 0){
            break;
        }

        pc.offset++;
        cpu.PC = pc;
    }
}