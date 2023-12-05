#include "battleship.h"

int main()
{
	// variable declarations (you'll need others, of course)
	bool done = false;
	string playerMove, computerMove;
	Board  playerBoard, computerBoard;
	int playerCheckResult, computerCheckResult;
	int playerRow, playerCol;
	int computerRow, computerCol;
	int playerSunkShips = 0;
        int computerSunkShips = 0;
	int playerMoveResult, computerMoveResult;
	
	string outputString = "";
	// Welcome the player to the game
	welcome(true);  //welcome();

	// Initialize the game boards
	initializeBoard(playerBoard);
	initializeBoard(computerBoard);

	// Play the game until one player has sunk the other's ships
	while (!done)
	{

		// Clear the screen to prepare show the game situation before the moves
		clearTheScreen();
		displayBoard(4, 0, 0, playerBoard);
		displayBoard(4, 35, 1, computerBoard);
	
		// Display the game board situation
		// Get and validate the human player's move
		// BTW, in the following while loop (and the if statements also), I have
		// put a "0" in with the comments.  This is because in order for the
		// code to compile, you need to have something in between the parentheses

		playerCheckResult = checkMove(playerMove, computerBoard, playerRow, playerCol);
		while (playerCheckResult != VALID_MOVE/* need to make sure that the human player's move is valid*/)
		{
			playerMove = getResponse(0, 0, "please input a move:");
		
			string tempStr = "";
			tempStr.push_back(playerMove.back());
			tempStr.push_back(toupper(playerMove.front()));
			playerMove = "";
			playerMove.push_back(tempStr.back());
			playerMove.push_back(tempStr.front());
			playerCol = playerMove.back() - 49;
			playerRow = playerMove.front() - 65;
			if(playerCol == -1) {
				playerCol = 9;
				playerMove.pop_back();
				playerMove.push_back('1');
				playerMove.push_back('0');
			}
			
			playerCheckResult = checkMove(playerMove, computerBoard, playerRow, playerCol);
			
			if(playerCheckResult != VALID_MOVE) {
			clearTheLine(0);
			outputString = playerMove + " is an Invalid Move";
			writeMessage(0, 0, outputString);
			pauseForEnter();
			clearTheLine(0);
			}
		}
	
		// Get and validate the computer's move
		computerMove = randomMove();
		computerCol = computerMove.back() - 47;
		computerRow = computerMove.front() - 64;
		
		computerCheckResult = checkMove(computerMove, playerBoard, computerRow, computerCol);
		
		// Execute both moves
		playerMoveResult = playMove(playerRow, playerCol, computerBoard);
		computerMoveResult = playMove(computerRow, computerCol, playerBoard);
		// Clear the screen to show the new game situation after the moves
		clearTheScreen();	
		// Display the new game board situation
		displayBoard(4, 0, 0, playerBoard);
		displayBoard(4, 35, 1, computerBoard);
			// Display the move choices each player made
		outputString = "You chose : " + playerMove;
		writeMessage(18, 0, outputString);
		
		if (isAMiss(playerMoveResult)) 
		{
			outputString = playerMove + " is a miss";
			writeMessage(21, 0, outputString);
		
				
		}

			outputString = "Computer chose : " + computerMove;
			writeMessage(19, 0, outputString);

		if (isAMiss(computerMoveResult)) 
		{
			writeMessage(22, 0, "Computer  misses");
				
		}			// Show the results of the moves
	
		if (isAHit(computerMoveResult)) 
		{
			outputString = computerMove + " is a Hit!";
			writeMessage(21, 0,  outputString);		       
				string ship = " your ";
				switch (isShip(computerMoveResult)) 
				{
					case 1:
						ship += "Aircraft Carrier";
						break;
					case 2:
						ship += "Battleship";
						break;
					case 3:
						ship += "Destroyer";
						break;
					case 4: 
						ship += "Submarine";
					       break;
					case 5: 
					       ship += "Patrol Boat";
						break;
					default: ship += "Not 1-5";
				  break;
				}
			outputString = "The computer hit " + ship;
			writeMessage(22, 0, outputString);	 
	
			if (isASunk(computerMoveResult)) 
			{
				computerSunkShips++;
			       	string ship = " your ";
				switch (isShip(computerMoveResult)) 
				{
					case 1:
						ship += "Aircraft Carrier";
						break;
					case 2:
						ship += "Battleship";
						break;
					case 3:
						ship += "Destroyer";
						break;
					case 4: 
						ship += "Submarine";
					       break;
					case 5: 
					       ship += "Patrol Boat";
						break;
					default: ship += "Not 1-5";
				  break;
				}
			outputString = "The computer hit and sunk" + ship;
				writeMessage(22, 0, outputString);	 
			}
		}
		if (isAHit(playerMoveResult)) 
		{
			outputString = playerMove + " is a Hit!";
			writeMessage(21, 0,  outputString);		       
			string ship = " the computer's ";
						switch (isShip(playerMoveResult)) 
				{
					case 1:
						ship += "Aircraft Carrier";
						break;
					case 2:
						ship += "Battleship";
						break;
					case 3:
						ship += "Destroyer";
						break;
					case 4: 
						ship += "Submarine";
					       break;
					case 5:
					       ship += "Patrol Boat";
						break;    
					default: ship += "Not 1-5";
				  break;
				}
			
			outputString = "You hit " + ship;
			writeMessage(22, 0, outputString);	 
	
			if (isASunk(playerMoveResult)) 
			{
				playerSunkShips++;
			       	string ship = " the computer's ";
					switch (isShip(playerMoveResult)) 
				{
					case 1:
						ship += "Aircraft Carrier";
						break;
					case 2:
						ship += "Battleship";
						break;
					case 3:
						ship += "Destroyer";
						break;
					case 4: 
						ship += "Submarine";
					       break;
					case 5: 
					       ship += "Patrol Boat";
						break;
					default: ship += "Not 1-5";
				  break;
				}
				outputString = "You hit and sunk" + ship;
				writeMessage(22, 0, outputString);	 
			}
		}
	
       			// Take note if there are any sunken ships

			// determine if we have a winner
			if (playerSunkShips >= 5 || computerSunkShips >= 5/* has either player sunk five ships? */)
			{
				// if one of the player's has sunk five ships the game is over
				done = true;
			}
			else
			{
				// pause to let the user assess the situation
				pauseForEnter();
			}
	}

	// Announce the winner:wq
	if (playerSunkShips >= 5/* the human was the winner */)
	{
		cout << "You won!!";
		/* You won!!! */
	}
	else
	{
		cout << "HA HA HA, Loser you got beat by a really stupid computer\n You should go end it now";
		/* The computer won :( */;
	}

	// pause to let the result of the game sink in

	return 0;
	}

