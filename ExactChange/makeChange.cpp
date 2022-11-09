#include <iostream>
#include <vector> 
using namespace std;

void ExactChange(int userTotal, vector<int>& coinVals) {
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;
	int tempUserTotal = userTotal;

	quarters = (tempUserTotal / 25);

	tempUserTotal = userTotal;
	tempUserTotal -= (25 * quarters);

	dimes = tempUserTotal / 10;

	tempUserTotal = userTotal;
	tempUserTotal -= (25 * quarters);
	tempUserTotal -= (10 * dimes);

	nickels = tempUserTotal / 5;

	tempUserTotal = userTotal;
	tempUserTotal -= (25 * quarters);
	tempUserTotal -= (10 * dimes);
	tempUserTotal -= (5 * nickels);

	pennies = tempUserTotal;

	coinVals.push_back(quarters);
	coinVals.push_back(dimes);
	coinVals.push_back(nickels);
	coinVals.push_back(pennies);

}

int main() {
	int inputVal;
	cin >> inputVal;
	vector<int> changeAmount;
	ExactChange(inputVal, changeAmount);
	int size = changeAmount.size();
	for (int i = 1; i <= size; i++) {
		switch (i)
		{
		case 1:
			if (changeAmount.back() == 1) {
				cout << changeAmount.back() << " penny";
			}
			else
				if (changeAmount.back() != 0) {
					cout << changeAmount.back() << " pennies";
				}

			break;
		case 2:
			if (changeAmount.back() == 1) {
				cout << changeAmount.back() << " nickel";
			}
			else
				if (changeAmount.back() != 0) {
					cout << changeAmount.back() << " nickels";
				}

			break;
		case 3:
			if (changeAmount.back() == 1) {
				cout << changeAmount.back() << " dime";
			}
			else
				if (changeAmount.back() != 0) {
					cout << changeAmount.back() << " dimes";
				}

			break;
		case 4:
			if (changeAmount.back() == 1) {
				cout << changeAmount.back() << " quarter";
			}
			else
				if (changeAmount.back() != 0) {

					cout << changeAmount.back() << " quarters";

				}
			break;
		default:
			cout << i << "broken";
			break;
		}
		changeAmount.pop_back();
	}
	return 0;
}
