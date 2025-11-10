#include "commands.h"
#include "utils.hpp"

void DEDUCT(){
  return;
}

//TODO till block 19(included)
//Finds puxxyy and pushes the data into the stack block which starts at 10 for now only 10 block is checked
void PUXXYY() {
    Converter converter;
    const int STACK_START = 10;  

    for (int i = 0; i < 5; ++i) {

        std::string codeBlock = getBlock(5 + i, VM_MEMORY_FILE);

        //Checking evey word in code segment
        for (int offset = 0; ; ++offset) {
            int start = 3 + offset * 7; //word reading logic


            //stops if no word left
            if (start + 6 > codeBlock.size()) {
                break;
            }
            
        
            std::string pu = getWord(codeBlock, offset);

            //word starts with PU
            if (pu.compare(0, 2, "PU") != 0) {
                continue;
            }

            //PUXXYY XX - data block YY - offset
            std::string xx_hex = pu.substr(2, 2);  //data block
            std::string yy_hex = pu.substr(4, 2);  //word offset

            //conversion to num
            int blockXX  = converter.hexToNum(xx_hex);
            int offsetYY = converter.hexToNum(yy_hex);

            // Read data word from data segment
            std::string dataBlock = getBlock(blockXX, VM_MEMORY_FILE);
            std::string dataWord = getWord(dataBlock, offsetYY);
            

            //stack
            std::string stackBlock = getBlock(STACK_START, VM_MEMORY_FILE);
            int freeOffset = -1; //will be useful in checking if stack is full

            for (int stackOff = 0; ; ++stackOff) {

                int stackStart = 3 + stackOff * 7;

                if (stackStart + 6 > stackBlock.size()){
                    break;
                }

                std::string stackWord = getWord(stackBlock, stackOff);
                if (stackWord == "------") {
                    freeOffset = stackOff;//if one space is found then stack has some free space and freeOffset value is changed
                    break;
                }
            }

            //stack is full
            if (freeOffset == -1) {
                return;
            }

            replaceBlockInFile(STACK_START, freeOffset, dataWord, VM_MEMORY_FILE); //push the word to stack
        }
    }
}

//needs address so for example Address programCounter {5, 0} will start at 0500 
//TODO checks all code segment blocks
//now only checks the 5 but it should be checked in seperate function
Address JDXXYY(const Address& programCounter) {
    Converter converter;

    //reads current code block
    std::string currentBlock = getBlock(programCounter.block, VM_MEMORY_FILE);

    //reads word ad offset
    std::string word = getWord(currentBlock, programCounter.offset);


    //checks if JD is found in that block if no just continues
    if (word.compare(0, 2, "JD") != 0) {
        return programCounter;
    }

    //JDXXYY XX - block YY - offset
    std::string xx = word.substr(2, 2);
    std::string yy= word.substr(4, 2);

    int jumpBlock  = converter.hexToNum(xx);
    int jumpOffset = converter.hexToNum(yy);

    
    //if jump happens creates new programCounter and program should start again from that memory address
    Address newProgramCounter;
    newProgramCounter.block  = jumpBlock;
    newProgramCounter.offset = jumpOffset;
    return newProgramCounter;
}
