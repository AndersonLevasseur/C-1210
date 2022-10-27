#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

vector<int> randomNumGen(int numOfNumsGenerated, int min, int max) {

	int randomNum;
	vector<int> output;

	srand(time(0));
	
	for (int i = 0; i < numOfNumsGenerated; i++) {
		randomNum = rand() % ((max - min + 1) + min);
		output.push_back(randomNum);
	}

	return output;
}

int main() {
	int numOfTimes = 0;
	cout << "How many times?\n";
	cin >> numOfTimes;
	int n;
	int min = 0;
	int max = 0;
	vector<int> randomNums;

	srand(time(0));

	cout << "please enter min\n";
	cin >> min;
	cout << "please enter max\n";
	cin >> max;

	randomNums = randomNumGen(numOfTimes, min, max);

	for (int i = 0; i < numOfTimes; i++) {
	n = randomNums.at(randomNums.size() - 1);
	randomNums.pop_back();

	cout << n << " ";
	}

	return 0;
}