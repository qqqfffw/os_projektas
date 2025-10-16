#include <fstream>
#include <iostream>
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
};

#define TOTAL_BLOCKS 256
#define BLOCK_SIZE 256

int main(){
  ofstream mem_file;
  Converter converter;

  mem_file.open("vm_mem.txt");

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

  return 0;
}