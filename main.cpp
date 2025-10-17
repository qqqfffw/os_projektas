#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Converter {
public:
   string toHex(int num1){
      if (num1 == 0)
         return "0";
      u_int num = num1;
      string s = "";
      while (num) {
         int temp = num % 16;
         if (temp <= 9)
            s += (48 + temp);
         else
            s += (87 + temp);
         num = num / 16;
      }
      reverse(s.begin(), s.end());
      return s;
   }

   // TODO:
   // Add hexToDec function 
};

string getBlock(int address, string fileName){
   Converter converter;
   string addressHex;
   ifstream file;

   
   if(address <= 15) addressHex = "0" + converter.toHex(address);
   else addressHex = converter.toHex(address);

   file.open(fileName);

   string line;
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

string getWords(int offset){
   return "d";
}

void replaceBlockInFile(int blockAddress, int offset, string newText, string fileName) {
   ifstream inFile(fileName);
   ostringstream buffer;
   string line;
   string blockAddressHex;
   Converter converter;
   bool replaced = false;

   blockAddressHex = converter.toHex(blockAddress);

   stringstream ssin(blockAddressHex);
   ssin >> hex >> blockAddress;

   stringstream ss;
   ss << hex << setw(2) << setfill('0') << nouppercase << blockAddress;
   string blockAddrStr = ss.str();

   cout << blockAddrStr << endl;

   while (getline(inFile, line)) {
      if (!replaced && line.substr(0, 3) == blockAddrStr + " ") {
         size_t start = 3 + offset * 7;
         if(start + 6 <= line.size()) {
            if(newText.size() <= 6){
               line.replace(start, newText.size(), newText);
            }else if(newText.size() > 6){
               while(newText.size() != 0){
                  string temp_text;
                  temp_text = newText.substr(0, 6);
                  line.replace(start, temp_text.size(), temp_text);
                  newText = newText.erase(0, 6);
                  start += 7;
                  //cout << newText << endl;
                  // replaceBlockInFile(blockAddress, offset+1, newText, fileName);
               }
            }

         }
         buffer << line << "\n";
         replaced = true;
      } else{
         buffer << line << "\n";
      }
   }
   inFile.close();

   ofstream outFile(fileName);
   outFile << buffer.str();
   outFile.close();
}

#define TOTAL_BLOCKS 256
#define BLOCK_SIZE 256
#define VM_MEMORY_FILE "vm_mem.txt"

int main(){
  ofstream mem_file;
  Converter converter;


  mem_file.open(VM_MEMORY_FILE);

  if(!mem_file.is_open()){
    return 1;
  }

  for(int i=0; i<TOTAL_BLOCKS; ++i){
    if (i <= 15) mem_file << "0" << converter.toHex(i) << " ";
    else mem_file << converter.toHex(i) << " ";

    for(int j=0; j<BLOCK_SIZE; ++j){
      mem_file << "------";
      mem_file << " ";
    }
    if(i != 255) mem_file << endl;
  }

  cout << "File created" << endl;

  mem_file.close();

  //string block;
  //block = getBlock(100, VM_MEMORY_FILE);

  replaceBlockInFile(10, 55, "hellow next ", VM_MEMORY_FILE);

  cout << getBlock(10, VM_MEMORY_FILE) << endl;
  return 0;
}