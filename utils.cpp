#include "utils.hpp"
#include <string>
#include <iostream>
#include <bits/stdc++.h>

class Converter{
   public:
      std::string numToHex(int num1){
         std::string v{};
         std::stringstream ss;
         ss << std::hex << std::nouppercase << num1;
         ss >> v;
         return v;
      }

      int hexToNum(std::string hexStr){
         int v{};
         std::stringstream ss(hexStr);
         ss >> std::hex >> v;
         return v;
      } 
};

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

   std::cout << blockAddrStr << std::endl;

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

