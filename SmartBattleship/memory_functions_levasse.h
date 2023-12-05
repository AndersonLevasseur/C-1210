#include <string>
#include "memory.h"

using namespace std;

void   initMemoryLevasse(ComputerMemory &memory);
void   updateMemoryLevasse(int row, int col, int result, ComputerMemory &memory);
string smartMoveLevasse(
	ComputerMemory &memory);

