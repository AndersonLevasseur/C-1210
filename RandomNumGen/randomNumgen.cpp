#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int numOfTimes = 0;
	cout << "How many times?\n";
	cin >> numOfTimes;
	int n;
	int min = 0;
	int max = 0;

	srand(time(0));
	cout << "please enter min\n";
	cin >> min;
	cout << "please enter max\n";
	cin >> max;

	for (int i = 0; i < numOfTimes; i++) {
	n = rand() % ((max - min + 1) + min);

	cout << n;
	}

	return 0;
}