#include <iostream>                     // for I/O
#include <cstring>                     // for strlen()
#include <cctype>                      // for toupper()
#include <vector>                      // for vectors
#include <string>
#include <array>                        // for arrays
#include <cstdlib>                      // for random numbers
#include <Windows.h>                     // for sleep()
//#include "ZyLab.h"                      // for ZyLab Setup

/*
This program is a simple memory game
Not case sensitive
Compile and run

TODO :
    Make it get faster as the levels progress
    Center Text?
    Multiple versions?
        full words vs. letters
            could run into an issue with spelling

*/



using namespace std;

int main(int argc, char** argv) {

    const int DEFAULT_NUMBER_OF_ROUNDS = 15;
    int       numRounds = DEFAULT_NUMBER_OF_ROUNDS;

    // if a command line argument is given, use that string to init the
    // "random" sequence and set the number of rounds to play the game
    if (argc == 2) {
        numRounds = strlen(argv[1]);
    }

    string    s;                         // A string used to pause the game
    string memoryString;                      // The current memory sequence
    char      c;                         // The player's typed characters
    char* seq = new char[numRounds];     // Sequence of numRounds colors to match
    char      colors[] = "RGBY";         // Allowable colors
    bool      lost = false;              // Indicates whether we win or lose
    int       round;                     // Indicates the current round

    // Initialize random number generator
    srand(time(0));

    // Determine the random color sequence using either argv[1] or
    // randomly determined letters from 'R', 'G', 'B', and 'Y'
    for (int j = 0; j < numRounds; j++) {
        seq[j] = (argc == 2) ? argv[1][j] : colors[rand() % 4];
    }

    // Wait until the player is ready
    cout << "Welcome to Simon says, see how long you can copy Simon! \nPress enter to play .... ";
    std::getline(cin, s, '\n');
    system("CLS");

    for (round = 0; round < numRounds; round++) {
        string playerInput;
        char colorIndicator;
        memoryString += seq[round];

        cout << "Simon says : ";

        for (int i = 0; i < memoryString.length(); i++) {
            char colorIndicator = seq[i];
            cout << colorIndicator;
            Sleep(1000);
            cout << '\010' << ".";
        }

        cout << "\nLevel: " << round + 1 << "\nPlease enter " << round + 1 << " characters to match Simon : ";
        std::getline(cin, playerInput, '\n');
        cout << '\014';
        system("CLS");

        if (playerInput != memoryString) {

            vector <char> backwardPlayerInput;
            string tempStrPlayerInput = playerInput;
            playerInput = "";
            char playerCharInput;

            /* converts playerInput to uppercase */
            for (int i = tempStrPlayerInput.length(); i > 0; i--) {
                playerCharInput = tempStrPlayerInput.front();
                tempStrPlayerInput = tempStrPlayerInput.substr(1, tempStrPlayerInput.length() - 1);
                playerInput += toupper(playerCharInput);
            }

            if (playerInput != memoryString) {
                lost = true; 
            }
        
        
        }


        if (lost) {
            cout << "You're a real big Loser \n";
            cout << "It was " << memoryString << endl;
            cout << "You failed on round " << round + 1 << "\n";
            round = numRounds;
        }
    }
    if (lost == false) {
        cout << "YOU ARE AMAZING";
    }
    return 0;
}