#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace constants{
  // Total memory sizes
  constexpr int TOTAL_BLOCKS = 256;
  constexpr int BLOCK_SIZE = 256;
  
  // Data segment
  constexpr int DATA_SEG_START = 0;
  constexpr int DATA_SEG_END = 4;

  // Code segment
  constexpr int CODE_SEG_START = 5;
  constexpr int CODE_SEG_END = 9;
  
  // Stack segment
  constexpr int STACK_SEG_START = 10;
  constexpr int STACK_SEG_END = 19;

  // General use
  constexpr int GENERAL_START = 20;
  constexpr int GENERAL_END = 255;
}

#endif
