#include "memory_functions_NNNN.h"

using namespace std;

void initMemoryLevasse(ComputerMemory &memory) {
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

string smartMoveLevasse(const ComputerMemory &memory) {
   // fill in the code here to make a smart move based on what information
   // appears in the computer's memory
string move;
	if (memory.mode == SEARCH || DESTROY)
	{
		//shoot around hit marker to find ship
		switch (memory.fireDirs[0]) {
			// might not be legal, might submit in inproper format 
		case NORTH:
			move = (memory.hitCol) + " " + (memory.hitRow + 1);
			break;
		case SOUTH:
			move = (memory.hitCol) + " " + (memory.hitRow - 1);
			break;
		case EAST:
			move = (memory.hitCol + 1) + " " + (memory.hitRow);
			break;
		case WEST:
			move = (memory.hitCol - 1) + " " + (memory.hitRow + 1);
			break;
		default:
			throw "firedir Error";
		}
		// check if previous shots have been fired
		//  switch statement going from North to South to East to West
		//keep track of shots so their isn't duplicates
	}
	else if (memory.mode == RANDOM)
	{
		int currentValue;
		int highestValue = memory.depth;
		//shoot next highest value on value board
			//need to use an efficient search
		while (currentValue < highestValue)
		{

		}

	}
	/****	This is where you actually do the shooting
		Decisions actually made in here, but lots of memory.*** calls are made
			Memory is where the data is actually stored
	string move
	int move row, col
	if memory mode is random
		shoot random



only allowed to modify memory in updateMemory

*/

	return move;

}

void updateMemoryLevasse(int row, int col, int result, ComputerMemory &memory) {
int hitOMiss = result/*0 for hit 1 for miss*/;

	// Need to check what result actually is
	cout << result;

	memory.grid[row][col] = -1;
	if (memory.lastResult == NONE)
	{
		// initialization
		memory.grid[0][0] = 10;
		memory.grid[0][1] = 2;
		memory.lastResult = 0;
		memory.hitShips[0] = 4;
		memory.fireDir = NORTH;
		memory.depth = 11;
	}
	if (memory.mode == RANDOM)
	{
		switch (hitOMiss)
		{
		case 0:
			//hit
			memory.mode = SEARCH;
			break;
		case 1:
			//miss so continue to shoot at "random" ***NOT NECASSARY***
			memory.mode = RANDOM;
			memory.depth = memory.grid[row][col];
			break;
		default:
			break;
		}
	}
	else if (memory.mode == SEARCH)
	{
		//if it is on the same ship
		if (hitOMiss == 1)
			// miss
		{
			//set fire direction 
			switch (memory.fireDir)
			{
			case NORTH:
				memory.fireDir = SOUTH;
				break;
			case SOUTH:
				memory.fireDir = EAST;
				break;
			case EAST:
				memory.fireDir = WEST;
				break;
			case WEST:
				memory.fireDir = NORTH;
				break;
			default:
				break;
			}
		}
		else
		{
			if (memory.hitShip == NONE)
			{
				memory.hitRow = row;
				memory.hitCol = col;
				memory.hitShip = isShip(result) /*doesn't like result*/;
				memory.hitShips[4] = memory.hitShip;
			}
			else if (memory.hitShips[0] < 5/*is the same as current hit ship*/)
			{
				int shipLoc = memory.hitShips[0];
				memory.hitShips[0] -= 1;
				memory.hitShips[shipLoc] = memory.hitShip;
			}
			//	set last hit
			//	look North, if the same shipand hit
			//	look south,
			//	look west,
			//	look east,

		}
	}
	else if (memory.mode == DESTROY)
	{
		switch (hitOMiss)
		{
		case 0:
			//hit 
			// check if sunk
			// ***check if its the same ship***
			if (result == 16)
			{
				// if hit and sunk
				// check for previous ships hit?
				// undo
				  // shiplast hit
				  // last hit
				  // hitdir
				  // 
				if (memory.hitShips[0] == 4)
				{
					memory.hitShips[4] = 0;
					memory.hitShip = NONE;
					memory.mode = RANDOM;
				}
				else
				{
					memory.hitShips[0] += 1;
					memory.hitShip = memory.hitShips[memory.hitShips[0]];
					memory.mode = SEARCH;
				}

			}
			else
			{
				// hit but not sunk
				// continue to fire in that direction
				memory.mode = DESTROY;
			}

		case 1:
			//miss
			memory.mode = DESTROY;
			memory.fireDir = NORTH/*opposite of current direction*/;
		default:
			break;
		}
	}
	memory.grid[row][col] = 0;
}

