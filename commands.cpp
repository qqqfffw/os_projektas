#include "commands.hpp"
#include "utils.hpp"

void DEDUCT(){
  return;
}

//TODO till block 19(included)
//Finds puxxyy and pushes the data into the stack block which starts at 10 for now only 10 block is checked
void PUXXYY(const std::string& pu) {
    Converter converter;
    const int STACK_START = 10;

    //XX - data block YY - data offset 
    std::string xx_hex = pu.substr(2, 2);
    std::string yy_hex = pu.substr(4, 2);


    int dataBlock  = converter.hexToNum(xx_hex);
    int dataOffset = converter.hexToNum(yy_hex);

    //read data seg
    std::string dataBlockLine = getBlock(dataBlock, VM_MEMORY_FILE);
    int dataStart = 3 + dataOffset * 7;
    std::string dataWord = getWord(dataBlockLine, dataOffset);

    //find free space in stack
    std::string stackBlock = getBlock(STACK_START, VM_MEMORY_FILE);
    int freeOffset = -1;//useful check

    for (int stackOff = 0; ; ++stackOff) {
        int stackStart = 3 + stackOff * 7;
        if (stackStart + 6 > (int)stackBlock.size()){
            break;
        }

        std::string stackWord = getWord(stackBlock, stackOff);
        if (stackWord == "------") {
            freeOffset = stackOff;
            break;
        }
    }

    if (freeOffset == -1){
      return; //stack is full
    }

    replaceBlockInFile(STACK_START, freeOffset, dataWord, VM_MEMORY_FILE);
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
    // if (word.compare(0, 2, "JD") != 0) {
    //     return programCounter;
    // }

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
