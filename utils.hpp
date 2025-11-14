#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "cpu.hpp"


#define VM_MEMORY_FILE "vm_mem.txt"


class Converter {
public:
	std::string numToHex(int num1);
	int hexToNum(std::string hexStr);
};

std::string getBlock(int, std::string);
std::string getBlock(int address, std::string fileName);
void replaceBlockInFile(int blockAddress, int offset, std::string newText, std::string fileName);
std::string getWord(std::string block, int offset);

void runProgram(CPU &cpu);


#endif