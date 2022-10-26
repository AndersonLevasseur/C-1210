#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	string userString;
	int output = 0;
	int n = 0;
	int i = 0;
	cin >> userString;
	int userStringLength = userString.length();

	for (i = 0; i < userStringLength; i++) {
		switch (userString.back()) {
		case '0':
			n++;
			break;
		case '1':
			output += pow(10, n);
			n++;
			break;
		case '2':
			output += (pow(10, n) * 2);
			n++;
			break;
		case '3':
			output += (pow(10, n) * 3);
			n++;
			break;
		case '4':
			output += (pow(10, n) * 4);
			n++;
			break;
		case '5':
			output += (pow(10, n) * 5);
			n++;
			break;
		case '6':
			output += (pow(10, n) * 6);
			n++;
			break;
		case '7':
			output += (pow(10, n) * 7);
			n++;
			break;
		case '8':
			output += (pow(10, n) * 8);
			n++;
			break;
		case '9':
			output += (pow(10, n) * 9);
			n++;
			break;
		case ',':
			if (i % 4 != 3) {
				output = 0;
				i = 99;
			}
			break;
		default:
			output = 0;
			i = 99;
		}
		userString.pop_back();
	}
	if (i == 100) {
		cout << "no ";
	} else {
		cout << "yes ";
	}
	cout << output << endl;
	return 0;
}
