#include "battleship.h"

int main()
{
	// variable declarations (you'll need others, of course)
	bool done = false;
	string playerMove,computerMove;
        Board  playerBoard, computerBoard;
        int playerCheckResult,computerCheckResult;
        int playerRow, playerCol;
	int computerRow, computerCol;
	// Welcome the player to the game
   welcome(true);  //welcome();

	// Initialize the game boards
   initializeBoard(playerBoard);
   initializeBoard(computerBoard);

	// Play the game until one player has sunk the other's ships
	while(!done)
	{

		// Clear the screen to prepare show the game situation before the moves
		clearTheScreen();
		// Display the game board situation
		// Get and validate the human player's move
		// BTW, in the following while loop (and the if statements also), I have
		// put a "0" in with the comments.  This is because in order for the
		// code to compile, you need to have something in between the parentheses
                 playerMove=getResponse(30,1,"please input a move:");
                 playerCheckResult=checkMove(playerMove, computerBoard, playerRow,playerCol);
		while(playerCheckResult!=VALID_MOVE/* need to make sure that the human player's move is valid*/)
		{
                 playerMove=getResponse(30,1,"please input a move:");
                 playerCheckResult=checkMove(playerMove, computerBoard, playerRow,playerCol);
			;
		}

		// Get and validate the computer's move
		while(0/* need to make sure that the computer's move is valid*/)
		{
			;
		}

		// Execute both moves
		// Clear the screen to show the new game situation after the moves
		// Display the new game board situation
		// Display the move choices each player made
		// Show the results of the moves
		// Take note if there are any sunken ships

		// determine if we have a winner
		if(0/* has either player sunk five ships? */)
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
	if(0/* the human was the winner */)
	{
		/* You won!!! */;
	}
	else
	{
		/* The computer won :( */;
	}

	// pause to let the result of the game sink in

	return 0;
}
