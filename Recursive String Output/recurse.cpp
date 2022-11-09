#include <iostream>
#include <string>
using namespace std;

void PrintPattern(int rows, string str, string chars, int nextChar = 1, int i = 1, int j = 0) {
	if (rows == 0) {
	}
	else {
		if (nextChar == 0) {
			// call again for next row
			cout << endl;
			PrintPattern(rows - 1, chars.substr(0, 1), chars, i + 1, i + 1);
		}
		else {
			// calls again for next char FIXME
		cout << str;
		PrintPattern(rows, chars.substr((j + 1) % chars.length(), 1), chars, nextChar - 1, i, j + 1);
		}
	}
	/* use both base and recursive cases to print successively longer versions
	   of str built from the character of chars                                */

}

int main() {
	string s = "";
	string c = "";
	int    n = 0;

	// cout << "How many rows in your pattern? ";
	cin >> n;

	// cout << "What characters should be used in the pattern? ";
	cin >> c;

	PrintPattern(n, c.substr(0, 1), c);

	return 0;
}
