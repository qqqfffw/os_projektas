#include <stdexcept>
#include "commands.hpp"
#include "utils.hpp"
#include "cpu.hpp"
#include "constants.hpp"

using namespace std;

void createMemoryTxt(){
   ofstream mem_file;
   Converter converter;

   mem_file.open(constants::VM_MEMORY_FILE);

   if(!mem_file.is_open()){
      cout << "Failed to open file" << endl;
      return;
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
}

void allocateMemory(){
   CPU::Byte *memPtr;
   memPtr = new CPU::Byte[6 * 256]{0}; // 

   for(int i = 0; i <= 5; ++i){
      cout << memPtr[i] << " ";
   }
}

int main(){
   CPU cpu;
   cpu.Reset();
   runProgram(cpu);

   int option = -1;
   cout << "Welcome!" << endl;
   cout << "\nSelect an option:" << endl;
   cout << "1. Create a new virtual machine." << endl;
   cout << "2. Exit." << endl;

   cin >> option;

   if(option == 1){
      cout << "Creating a new virtual machine..." << endl;
   }else if(option == 2){
      cout << "Exiting..." << endl;
      return 0;
   }else{
      cout << "Failed to select an option. Exiting..." << endl;
      return 0;
   }

   return 0;
}