#include "memory_functions_NNNN.h"

using namespace std;

void initMemoryNNNN(ComputerMemory &memory) {
   memory.mode        =  RANDOM;
   memory.hitRow      = -1;
   memory.hitCol      = -1;
   memory.hitShip     =  NONE;
   memory.fireDir     =  NONE;
   memory.fireDist    =  1;
   memory.lastResult  =  NONE;

   for (int i = 0; i < BOARDSIZE; i++) {
      for (int j = 0; j < BOARDSIZE; j++) {
         memory.grid[i][j] = EMPTY_MARKER;
      }
   }
}

string smartMoveNNNN(const ComputerMemory &memory) {
   // fill in the code here to make a smart move based on what information
   // appears in the computer's memory
   string move;

   return move;
}

void updateMemoryNNNN(int row, int col, int result, ComputerMemory &memory) {

}

