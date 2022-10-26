//Case sensitive
// enter target letter, " " then string you want to 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inputStr;
    char targetChar;
    std::cin >> targetChar;
    std::getline(std::cin, inputStr);
    const string outputStr = inputStr;
    
    int numTargetCharInputs = 0;
    

    while(inputStr.length() > 0) {
    char inputChar = inputStr.back();

        if (inputChar == targetChar) {
            numTargetCharInputs++;
        }
        inputStr.pop_back();
    }
    if (numTargetCharInputs == 1) {
        std::cout << numTargetCharInputs << " " << targetChar;
    }
    std::cout << numTargetCharInputs << " " << targetChar << "'s";

}
