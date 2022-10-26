//it's ok that it has 2 for loops doing the same thing
// if it didn't the output would be backwards
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string inputStr;
    char targetChar;
    vector <char> charStr;
    std::cin >> inputStr;
    int length = inputStr.length();
    
    for (int i = 0; i < length; i++) {
        charStr.push_back(inputStr.back());
        inputStr.pop_back();
    }
    for (int i = 0; i < length; i++) {
        if (charStr.back() >= 97 && charStr.back() <= 122) {
            charStr.back() = charStr.back() - 32;
        }
        inputStr.push_back(charStr.back());
        charStr.pop_back();
    }
    cout << inputStr;
    return 0;
}