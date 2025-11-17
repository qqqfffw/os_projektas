#include "utils.hpp"
#include "cpu.hpp"
#include "constants.hpp"

std::string Converter::numToHex(int num1) {
   std::string v{};
   std::stringstream ss;
   ss << std::hex << std::nouppercase << num1;
   ss >> v;
   return v;
}

int Converter::hexToNum(std::string hexStr) {
   int v{};
   std::stringstream ss(hexStr);
   ss >> std::hex >> v;
   return v;
}

Converter converter;

std::string getBlock(int address, std::string fileName){
   std::string addressHex;
   std::ifstream file;
   Converter converter;

   if(address <= 15) addressHex = "0" + converter.numToHex(address);
   else addressHex = converter.numToHex(address);

   file.open(fileName);

   std::string line;
   if(file.is_open()){
      while(getline(file, line)){
         if(line.substr(0, 3) == addressHex + " "){
            file.close();
            return line;
         }
      }
   }

   file.close();

   return addressHex;
}

void replaceBlockInFile(int blockAddress, int offset, std::string newText, std::string fileName) {
   std::ifstream inFile(fileName);
   std::ostringstream buffer;
   std::string line;
   std::string blockAddressHex;
   Converter converter;
   bool replaced = false;

   blockAddressHex = converter.numToHex(blockAddress);

   std::stringstream ssin(blockAddressHex);
   ssin >> std::hex >> blockAddress;

   std::stringstream ss;
   ss << std::hex << std::setw(2) << std::setfill('0') << std::nouppercase << blockAddress;
   std::string blockAddrStr = ss.str();

   //std::cout << blockAddrStr << std::endl;

   while (getline(inFile, line)) {
      if (!replaced && line.substr(0, 3) == blockAddrStr + " ") {
         size_t start = 3 + offset * 7;
         if(start + 6 <= line.size()) {
            if(newText.size() <= 6){
               line.replace(start, newText.size(), newText);
            }else if(newText.size() > 6){
               while(newText.size() != 0){
                  std::string temp_text;
                  temp_text = newText.substr(0, 6);
                  line.replace(start, temp_text.size(), temp_text);
                  newText = newText.erase(0, 6);
                  start += 7;
                  // cout << newText << endl;
                  // replaceBlockInFile(blockAddress, offset+1, newText, fileName);
               }
            }
         }
         buffer << line << "\n";
         replaced = true;
      }else{
         buffer << line << "\n";
      }
   }
   inFile.close();

   std::ofstream outFile(fileName);
   outFile << buffer.str();
   outFile.close();
}

std::string getWord(std::string block, int offset){
   std::string word;
   size_t start = 3 + offset * 7;
   word = block.substr(start, 6);
   
   return word;
}

void prepareProgram(){
   std::string block = getBlock(constants::GENERAL_START, constants::VM_MEMORY_FILE);
   int counter = 0;
   int offset = 0;
   int offset_start, offset_end = 0;
   std::string current_word;

   // Find the whole program code in memory.
   int star_counter = 0;
   while(1){
      current_word = getWord(block, offset);

      
      if(current_word == "******" && star_counter == 0){
         offset_start = offset;
         star_counter += 1;
      }else if(current_word == "******" && star_counter == 1){
         offset_end = offset;
         star_counter += 1;
      }
      
      if(star_counter == 2) break;
      offset += 1;
   }
   
   int status = 0; // 0 -- nothing/start/title; 1 -- ..data segment; 2 -- ..code segment
   int current_offset = offset_start;
   int code_offset = 0;
   int data_offset = 0;
   while(current_offset < offset_end){
      current_word = getWord(block, current_offset);

      if(current_word == "..data"){
         status = 1;
         // Skip word "..data" (no need to write it to the mem) and get new word 
         current_offset += 1;
         current_word = getWord(block, current_offset);
      }
      else if(current_word == "..code"){
         status = 2;
         // Skip word "..code" (no need to write it to the mem) and get new word
         current_offset += 1;
         current_word = getWord(block, current_offset);
      }

      switch(status){
         case 0:
            // Skip start stars and title
            current_offset += 2;
            break;
         case 1:
            // Put all of the data in the data segment
            replaceBlockInFile(constants::DATA_SEG_START, data_offset, current_word.substr(3), constants::VM_MEMORY_FILE); 
            data_offset += 1;
            current_offset += 1;
            break;
         case 2:
            // Put all of the commands into the code segment
            replaceBlockInFile(constants::CODE_SEG_START, code_offset, current_word, constants::VM_MEMORY_FILE); 
            code_offset += 1;
            current_offset += 1;
            break;
      }
   }
}
