#include "memory_functions_levasse.h"

using namespace std;

void initMemoryLevasse(ComputerMemory& memory) {
	memory.mode = RANDOM;
	memory.hitRow = -1;
	memory.hitCol = -1;
	memory.hitShip = NONE;
	memory.fireDir = NONE;
	memory.fireDist = 1;
	memory.lastResult = NONE;
	memory.depth = 0;

	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			memory.grid[i][j] = EMPTY_MARKER;
		}
	}
}

string smartMoveLevasse(const ComputerMemory& memory) {
	// fill in the code here to make a smart move based on what information
	// appears in the computer's memory
	string move = "";
	debug("mode " + numToString(memory.mode));
	if (memory.mode != RANDOM)
	{
		//shoot around hit marker to find ship
		debug("Hit ship : " + numToString(memory.hitShip));
		debug("last Result : " + numToString(memory.lastResults[memory.hitShip]));
		debug("Fire Direction : " + numToString(memory.fireDirs[memory.hitShip]));
		debug("Fire Distance : " + numToString(memory.fireDist));
		debug("searchCol : " + numToString(memory.hitCol));
		debug("searchRow : " + numToString(memory.hitRow));
		switch (memory.fireDirs[memory.hitShip]) {
		case NORTH:
			move = char(memory.hitRow + 97 - memory.fireDist) + numToString(memory.hitCol + 1);
			break;
		case SOUTH:
			move = char(memory.hitRow + 97 + memory.fireDist) + numToString(memory.hitCol + 1);
			break;
		case EAST:
			move = char(memory.hitRow + 97) + numToString(memory.hitCol + 1 + memory.fireDist);
			break;
		case WEST:
			move = char(memory.hitRow + 97) + numToString(memory.hitCol + 1 - memory.fireDist);
			break;
		default:
			throw "firedir Error";
			break;
		}
		// check if previous shots have been fired ^^
		//  switch statement going from North to South to East to West ^^

		//keep track of shots so there isn't duplicates DO AT END OF PORGRAM done
	}
	else if (memory.mode == RANDOM)
	{
		int currentValue;
		//shoot next highest value on value board
			//need to use an efficient search
				//going to be O(n) 
		int highestNum = -90;
		char row = 'Z';
		int column = -1;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (memory.grid[i][j] >= highestNum)
				{
					row = i + 97;
					column = j + 1;
					highestNum = memory.grid[i][j];
				}

			}
		}
		move = row + numToString(column);
		int i = row - 97;
	}
	// Move formatted as CapitalLetterNumber
	return move;

}

void updateMemoryLevasse(int row, int col, int result, ComputerMemory& memory) {
	bool hitOMiss = isAHit(result)/*0 for miss 1 for hit*/;

	//Things that need to be done every single time
	memory.grid[row][col] = -1;
	//Initiation case
	if (memory.depth == 0)
	{
		// initialization
		/*tile weight initialization*/ {
			memory.grid[0][0] = 4;
			memory.grid[0][1] = 0;
			memory.grid[0][2] = 10;
			memory.grid[0][3] = 0;
			memory.grid[0][4] = 5;
			memory.grid[0][5] = 0;
			memory.grid[0][6] = 6;
			memory.grid[0][7] = 2;
			memory.grid[0][8] = 4;
			memory.grid[0][9] = 1;
			memory.grid[1][0] = 0;
			memory.grid[1][1] = 8;
			memory.grid[1][2] = 0;
			memory.grid[1][3] = 7;
			memory.grid[1][4] = 0;
			memory.grid[1][5] = 4;
			memory.grid[1][6] = 2;
			memory.grid[1][7] = 6;
			memory.grid[1][8] = 1;
			memory.grid[1][9] = 4;
			memory.grid[2][0] = 10;
			memory.grid[2][1] = 0;
			memory.grid[2][2] = 5;
			memory.grid[2][3] = 0;
			memory.grid[2][4] = 6;
			memory.grid[2][5] = 2;
			memory.grid[2][6] = 4;
			memory.grid[2][7] = 1;
			memory.grid[2][8] = 6;
			memory.grid[2][9] = 10;
			memory.grid[3][0] = 0;
			memory.grid[3][1] = 7;
			memory.grid[3][2] = 0;
			memory.grid[3][3] = 4;
			memory.grid[3][4] = 2;
			memory.grid[3][5] = 6;
			memory.grid[3][6] = 1;
			memory.grid[3][7] = 4;
			memory.grid[3][8] = 0;
			memory.grid[3][9] = 6;
			memory.grid[4][0] = 5;
			memory.grid[4][1] = 0;
			memory.grid[4][2] = 6;
			memory.grid[4][3] = 2;
			memory.grid[4][4] = 4;
			memory.grid[4][5] = 1;
			memory.grid[4][6] = 6;
			memory.grid[4][7] = 0;
			memory.grid[4][8] = 4;
			memory.grid[4][9] = 0;
			memory.grid[5][0] = 0;
			memory.grid[5][1] = 4;
			memory.grid[5][2] = 2;
			memory.grid[5][3] = 6;
			memory.grid[5][4] = 1;
			memory.grid[5][5] = 4;
			memory.grid[5][6] = 0;
			memory.grid[5][7] = 6;
			memory.grid[5][8] = 0;
			memory.grid[5][9] = 9;
			memory.grid[6][0] = 6;
			memory.grid[6][1] = 2;
			memory.grid[6][2] = 4;
			memory.grid[6][3] = 1;
			memory.grid[6][4] = 6;
			memory.grid[6][5] = 0;
			memory.grid[6][6] = 4;
			memory.grid[6][7] = 0;
			memory.grid[6][8] = 10;
			memory.grid[6][9] = 0;
			memory.grid[7][0] = 2;
			memory.grid[7][1] = 6;
			memory.grid[7][2] = 1;
			memory.grid[7][3] = 4;
			memory.grid[7][4] = 0;
			memory.grid[7][5] = 6;
			memory.grid[7][6] = 0;
			memory.grid[7][7] = 9;
			memory.grid[7][8] = 0;
			memory.grid[7][9] = 6;
			memory.grid[8][0] = 4;
			memory.grid[8][1] = 1;
			memory.grid[8][2] = 6;
			memory.grid[8][3] = 0;
			memory.grid[8][4] = 4;
			memory.grid[8][5] = 0;
			memory.grid[8][6] = 11;
			memory.grid[8][7] = 0;
			memory.grid[8][8] = 4;
			memory.grid[8][9] = 0;
			memory.grid[9][0] = 1;
			memory.grid[9][1] = 4;
			memory.grid[9][2] = 0;
			memory.grid[9][3] = 6;
			memory.grid[9][4] = 0;
			memory.grid[9][5] = 9;
			memory.grid[9][6] = 0;
			memory.grid[9][7] = 6;
			memory.grid[9][8] = 0;
			memory.grid[9][9] = 4;



		}
		/*last result init*/
		if (true) {
			memory.lastResults[0] = 5;
			memory.lastResults[1] = 4;
			memory.lastResults[2] = 3;
			memory.lastResults[3] = 3;
			memory.lastResults[4] = 2;
			memory.fireDirs[0] = 0;
			memory.fireDirs[1] = 0;
			memory.fireDirs[2] = 0;
			memory.fireDirs[3] = 0;
			memory.fireDirs[4] = 0;
			memory.fireDists[0] = 0;
			memory.fireDists[1] = 0;
			memory.fireDists[2] = 0;
			memory.fireDists[3] = 0;
			memory.fireDists[4] = 0;
			memory.hitShips[0] = 0;
			memory.hitShips[1] = 0;
			memory.hitShips[2] = 0;
			memory.hitShips[3] = 0;
			memory.hitShips[4] = 0;
		}
		memory.depth = 10;
		// hit on irst shot?
		memory.grid[9][9] = -1;
	}
	//Radnom
	if (memory.mode == RANDOM)
	{
		if (hitOMiss)
		{
			//hit
			memory.hitShip = isShip(result) - 1;

			memory.fireDists[memory.hitShip] = 1;
			memory.mode = SEARCH;
			memory.hitCol = col;
			memory.hitRow = row;
			memory.hitRows[memory.hitShip] = memory.hitRow;
			memory.hitCols[memory.hitShip] = memory.hitCol;
			memory.hitCols[memory.hitShip] = col;
			memory.hitRows[memory.hitShip] = row;
			memory.lastResults[memory.hitShip]--;

			if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
			{
				memory.fireDirs[memory.hitShip] = NORTH;
				memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
			}
			else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
			{
				memory.fireDirs[memory.hitShip] = SOUTH;
				memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

			}
			else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
			{
				memory.fireDirs[memory.hitShip] = EAST;
				memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

			}
			else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
			{
				memory.fireDirs[memory.hitShip] = WEST;
				memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

			}
		}
		else
		{
			//miss so continue to shoot at "random" ***NOT NECASSARY***
			memory.mode = RANDOM;
			//memory.depth = memory.grid[row][col];
		}
	}
	//Search
	else if (memory.mode == SEARCH)
	{
		//if it is on the same ship
		// hit
		if (hitOMiss)
		{
			if (memory.hitShip == 4 && isShip(result) == 5)
			{
				memory.fireDist = 1;
				memory.fireDists[memory.hitShip] = 1;
				memory.hitShips[memory.hitShip] = NONE;
				memory.hitShip = NONE;
				memory.mode = RANDOM;
				// if hit and sunk
				// check for previous ships hit?
				switch (memory.hitShip)
				{
				case 0:
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++) {
							if ((memory.grid[i][j] % 2) == 1) {
								memory.grid[i][j] = memory.grid[i][j] - 1;
							}
						}
					}
					break;
				case 1:
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++) {
							if ((memory.grid[i][j] == 6) || (memory.grid[i][j] == 7) || (memory.grid[i][j] == 10) || (memory.grid[i][j] == 11)) {
								memory.grid[i][j] = memory.grid[i][j] - 2;
							}
						}
					}
					break;
				case 2:
				case 3:
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++) {
							if ((memory.grid[i][j] == 2) || (memory.grid[i][j] == 3))
							{
								memory.grid[i][j] = memory.grid[i][j] - 2;
							}
							if ((memory.grid[i][j] == 8) || (memory.grid[i][j] == 10) || (memory.grid[i][j] == 11))
							{
								memory.grid[i][j] = memory.grid[i][j] - 4;
							}

						}
					}
					break;
				case 4:
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++) {
							if ((memory.grid[i][j] == 4) || (memory.grid[i][j] == 5)) {
								memory.grid[i][j] = memory.grid[i][j] - 4;
							}
							if ((memory.grid[i][j] == 6) || (memory.grid[i][j] == 7))
							{
								memory.grid[i][j] = memory.grid[i][j] - 4;
							}
							if (memory.grid[i][j] > 6)
							{
								memory.grid[i][j] = memory.grid[i][j] - 6;
							}
						}
					}
					break;

				}



				for (int i = 0; i < 5; i++)
				{
					if (memory.hitShips[i] != 0)
					{
						memory.hitShip = isShip(memory.hitShips[i]) - 1;
						memory.hitCol = memory.hitCols[memory.hitShip];
						memory.hitRow = memory.hitRows[memory.hitShip];
						memory.mode = SEARCH;
						// going to save fireDir in an array so I can go back easy
						memory.fireDist = memory.fireDists[memory.hitShip];
						i = 5;
					}
				}
			}
			else
			{
				if (memory.hitShip == isShip(result) - 1)
				{
					memory.fireDist++;
					memory.fireDists[memory.hitShip] = memory.fireDist;
					memory.lastResults[memory.hitShip]--;
					memory.mode = DESTROY;
					if ((row == 9 && memory.fireDir == SOUTH) || (row == 0 && memory.fireDir == NORTH) || (col == 9 && memory.fireDir == EAST) || (col == 0 && memory.fireDir == WEST) || (memory.grid[row + 1][col] == -1 && memory.fireDir == SOUTH) || (memory.grid[row - 1][col] == -1 && memory.fireDir == NORTH) || (memory.grid[row][col + 1] == -1 && memory.fireDir == EAST) || ((memory.grid[row][col - 1] == -1 && memory.fireDir == WEST)))
					{
						//switches direction if close to a border
						switch (memory.fireDirs[memory.hitShip])
						{
						case NORTH:
							memory.fireDirs[memory.hitShip] = SOUTH;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case SOUTH:
							memory.fireDirs[memory.hitShip] = NORTH;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case EAST:
							memory.fireDirs[memory.hitShip] = WEST;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case WEST:
							memory.fireDirs[memory.hitShip] = EAST;
							memory.fireDists[memory.hitShip] = 1;
							break;
						}
					}

					//set fire direction already
					// could check if you can continue to shoot in same direction
				}
				else
				{
					if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
					{
						memory.fireDirs[memory.hitShip] = NORTH;
						memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
					}
					else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
					{
						memory.fireDirs[memory.hitShip] = SOUTH;
						memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

					}
					else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
					{
						memory.fireDirs[memory.hitShip] = EAST;
						memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

					}
					else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
					{
						memory.fireDirs[memory.hitShip] = WEST;
						memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

					}
					//old ship
					memory.hitCol = memory.hitCols[memory.hitShip];
					memory.hitRow = memory.hitRows[memory.hitShip];
					memory.hitShips[memory.hitShip] = memory.hitShip + 1;
					memory.fireDir = memory.fireDirs[memory.hitShip];
					memory.fireDists[memory.hitShip] = 1;
					memory.fireDist = 1;

					//new ship
					memory.hitShip = isShip(result) - 1;

					memory.fireDists[memory.hitShip] = 1;
					memory.fireDist = 1;

					memory.hitShips[memory.hitShip] = memory.hitShip + 1;

					memory.hitCol = col;
					memory.hitRow = row;
					memory.hitRows[memory.hitShip] = memory.hitRow;
					memory.hitCols[memory.hitShip] = memory.hitCol;

					memory.lastResults[memory.hitShip]--;

					if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
					{
						memory.fireDirs[memory.hitShip] = NORTH;
						memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
					}
					else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
					{
						memory.fireDirs[memory.hitShip] = SOUTH;
						memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

					}
					else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
					{
						memory.fireDirs[memory.hitShip] = EAST;
						memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

					}
					else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
					{
						memory.fireDirs[memory.hitShip] = WEST;
						memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

					}

					// Not necessary but clear			
					memory.mode = SEARCH;
				}
			}
		}
		else
		{
			// SEARCH Miss
			if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
			{
				memory.fireDirs[memory.hitShip] = NORTH;
				memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
			}
			else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
			{
				memory.fireDirs[memory.hitShip] = SOUTH;
				memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

			}
			else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
			{
				memory.fireDirs[memory.hitShip] = EAST;
				memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

			}
			else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
			{
				memory.fireDirs[memory.hitShip] = WEST;
				memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

			}
			//	set last hit
			//	look North, if the same shipand hit
			//	look south,
			//	look west,
			//	look east,

		}
	}
	//destroy
	else if (memory.mode == DESTROY)
	{
		if (hitOMiss)
		{
			//hit 
			// check if sunk
			// ***check if its the same ship***
			if (isShip(result) - 1 == memory.hitShip)
			{
				if (memory.lastResults[memory.hitShip] <= 1)
				{
					memory.fireDist = 1;
					memory.fireDists[memory.hitShip] = 1;
					memory.hitShips[memory.hitShip] = NONE;
					memory.hitShip = NONE;
					memory.mode = RANDOM;
					// if hit and sunk
					// check for previous ships hit?
					switch (memory.hitShip)
					{
					case 0:
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++) {
								if ((memory.grid[i][j] % 2) == 1) {
									memory.grid[i][j] = memory.grid[i][j] - 1;
								}
							}
						}
						break;
					case 1:
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++) {
								if ((memory.grid[i][j] == 6) || (memory.grid[i][j] == 7) || (memory.grid[i][j] == 10) || (memory.grid[i][j] == 11)) {
									memory.grid[i][j] = memory.grid[i][j] - 2;
								}
							}
						}
						break;
					case 2:
					case 3:
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++) {
								if ((memory.grid[i][j] == 2) || (memory.grid[i][j] == 3))
								{
									memory.grid[i][j] = memory.grid[i][j] - 2;
								}
								if ((memory.grid[i][j] == 8) || (memory.grid[i][j] == 10) || (memory.grid[i][j] == 11))
								{
									memory.grid[i][j] = memory.grid[i][j] - 4;
								}

							}
						}
						break;
					case 4:
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++) {
								if ((memory.grid[i][j] == 4) || (memory.grid[i][j] == 5)) {
									memory.grid[i][j] = memory.grid[i][j] - 4;
								}
								if ((memory.grid[i][j] == 6) || (memory.grid[i][j] == 7))
								{
									memory.grid[i][j] = memory.grid[i][j] - 4;
								}
								if (memory.grid[i][j] > 6)
								{
									memory.grid[i][j] = memory.grid[i][j] - 6;
								}
							}
						}
						break;

					}



					for (int i = 0; i < 5; i++)
					{
						if (memory.hitShips[i] != 0)
						{
							memory.hitShip = isShip(memory.hitShips[i]) - 1;
							memory.hitCol = memory.hitCols[memory.hitShip];
							memory.hitRow = memory.hitRows[memory.hitShip];
							memory.mode = SEARCH;
							// going to save fireDir in an array so I can go back easy
							memory.fireDist = memory.fireDists[memory.hitShip];
							i = 5;
							
						}
					}



				}
				else
					// hit but not sunk
					// continue to fire in that direction
				{
					memory.lastResults[memory.hitShip]--;
					memory.fireDist++;
					memory.fireDists[memory.hitShip] = memory.fireDist;
					if ((row == 9 && memory.fireDir == SOUTH) || (row == 0 && memory.fireDir == NORTH) || (col == 9 && memory.fireDir == EAST) || (col == 0 && memory.fireDir == WEST) || (memory.grid[row + 1][col] == -1 && memory.fireDir == SOUTH) || (memory.grid[row - 1][col] == -1 && memory.fireDir == NORTH) || (memory.grid[row][col + 1] == -1 && memory.fireDir == EAST) || ((memory.grid[row][col - 1] == -1 && memory.fireDir == WEST)))
					{
						//switches direction if close to a border
						switch (memory.fireDirs[memory.hitShip])
						{
						case NORTH:
							memory.fireDirs[memory.hitShip] = SOUTH;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case SOUTH:
							memory.fireDirs[memory.hitShip] = NORTH;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case EAST:
							memory.fireDirs[memory.hitShip] = WEST;
							memory.fireDists[memory.hitShip] = 1;
							break;
						case WEST:
							memory.fireDirs[memory.hitShip] = EAST;
							memory.fireDists[memory.hitShip] = 1;
							break;
						}
					}

					memory.fireDist = memory.fireDists[memory.hitShip];
				}
			}
			else
			{
				if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
				{
					memory.fireDirs[memory.hitShip] = NORTH;
					memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
				}
				else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
				{
					memory.fireDirs[memory.hitShip] = SOUTH;
					memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

				}
				else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
				{
					memory.fireDirs[memory.hitShip] = EAST;
					memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

				}
				else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
				{
					memory.fireDirs[memory.hitShip] = WEST;
					memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

				}
				//old ship
				memory.hitCol = memory.hitCols[memory.hitShip];
				memory.hitRow = memory.hitRows[memory.hitShip];
				memory.hitShips[memory.hitShip] = memory.hitShip + 1;
				memory.fireDir = memory.fireDirs[memory.hitShip];
				memory.fireDists[memory.hitShip] = 1;
				memory.fireDist = 1;

				//new ship
				memory.hitShip = isShip(result) - 1;

				memory.fireDists[memory.hitShip] = 1;
				memory.fireDist = 1;

				memory.hitShips[memory.hitShip] = memory.hitShip + 1;

				memory.hitCol = col;
				memory.hitRow = row;
				memory.hitRows[memory.hitShip] = memory.hitRow;
				memory.hitCols[memory.hitShip] = memory.hitCol;

				memory.lastResults[memory.hitShip]--;

				if (memory.hitRow != 0 && memory.grid[memory.hitRow - 1][memory.hitCol] != -1)
				{
					memory.fireDirs[memory.hitShip] = NORTH;
					memory.grid[memory.hitRow - 1][memory.hitCol] = -1;
				}
				else if (memory.hitRow != 9 && memory.grid[memory.hitRow + 1][memory.hitCol] != -1)
				{
					memory.fireDirs[memory.hitShip] = SOUTH;
					memory.grid[memory.hitRow + 1][memory.hitCol] = -1;

				}
				else if (memory.hitCol != 0 && memory.grid[memory.hitRow][memory.hitCol + 1] != -1)
				{
					memory.fireDirs[memory.hitShip] = EAST;
					memory.grid[memory.hitRow][memory.hitCol + 1] = -1;

				}
				else if (memory.hitCol != 9 && memory.grid[memory.hitRow][memory.hitCol - 1] != -1)
				{
					memory.fireDirs[memory.hitShip] = WEST;
					memory.grid[memory.hitRow][memory.hitCol - 1] = -1;

				}

				memory.mode = SEARCH;
			}
		}
		else
		{
			//miss or undefined
			memory.mode = DESTROY;
			/*opposite of current direction*/
			switch (memory.fireDirs[memory.hitShip])
			{
			case NORTH:
				memory.fireDirs[memory.hitShip] = SOUTH;
				memory.fireDists[memory.hitShip] = 1;
				break;
			case SOUTH:
				memory.fireDirs[memory.hitShip] = NORTH;
				memory.fireDists[memory.hitShip] = 1;
				break;
			case EAST:
				memory.fireDirs[memory.hitShip] = WEST;
				memory.fireDists[memory.hitShip] = 1;
				break;
			case WEST:
				memory.fireDirs[memory.hitShip] = EAST;
				memory.fireDists[memory.hitShip] = 1;
				break;
			}
			memory.fireDist = memory.fireDists[memory.hitShip];

		}
	}
	memory.fireDist = memory.fireDists[memory.hitShip];
	memory.fireDir = memory.fireDirs[memory.hitShip];

}


