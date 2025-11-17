#include "commands.hpp"
#include "utils.hpp"
#include "cpu.hpp"
#include "constants.hpp"

using namespace std;

//#define TOTAL_BLOCKS 256
//#define BLOCK_SIZE 256
//#define STACK_SEG_START 10
//#define STACK_SEG_END 19
//#define DATA_SEG_START 0

int main(){
   ofstream mem_file;
   Converter converter;
   CPU cpu;
   mem_file.open(constants::VM_MEMORY_FILE);

   if(!mem_file.is_open()){
      return 1;
   }

   for(int i=0; i<constants::TOTAL_BLOCKS; ++i){
      if (i <= 15) mem_file << "0" << converter.numToHex(i) << " ";
      else mem_file << converter.numToHex(i) << " ";

      for(int j=0; j<constants::BLOCK_SIZE; ++j){
         mem_file << "------";
         mem_file << " ";
      }
      if(i != 255) mem_file << endl;
   }

   cout << "File created" << endl;

   mem_file.close();
   
   prepareProgram();

   cpu.Reset();
   runProgram(cpu);

   return 0;
}