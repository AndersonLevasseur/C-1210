#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	int squareNum = 0;
	int i;
	
	cout << "Please enter Perfect Square number\n";
	cin >> squareNum;
	int digitNumMax = 0;
	vector <int> tempArr(pow(squareNum, 2));
	vector <int> arr(pow(squareNum, 2));

	tempArr.erase(tempArr.begin(), tempArr.end());
	
	for (i = pow(squareNum, 2); i > 0; i--) {
		int tempNum = 0;
		cout << i  << " Digits remaining\n" << "Please enter next square digit : \n";
		cin >> tempNum;
		
		if (tempNum / 10 > digitNumMax && tempNum / 10 < 9) {
			digitNumMax = tempNum;
		}

		system("CLS");
		tempArr.push_back(tempNum);
	}
	
	for (i = pow(squareNum, 2); i > 0; i--) {
		int tempNum = 0;
		tempNum = tempArr.back();
		tempArr.pop_back();
		system("CLS");
		arr.push_back(tempNum);
	}

	/*if (true) {
		vector <int> rowSumArr(pow(squareNum, 2));
		vector <int> tempRowSumArr(pow(squareNum, 2));
		tempRowSumArr = arr;
		for (int i = 0; i < squareNum; i++) {
			int tempRowSum = 0;
			int j = 1;
			while (j % squareNum + 1 != 0) {
				tempRowSum += tempRowSumArr.back();
				cout << tempRowSumArr.back();

				tempRowSumArr.pop_back();
				j++;
			}
			cout << tempRowSum << endl;
			if (tempRowSum != rowSumArr.back() && i != 0) {
				cout << "Error : row sum off";
				throw "Error : row sum off";
			}

			cout << i << endl;
			
			rowSumArr.push_back(tempRowSum);
		}
		cout << "Golden they are all the same";
	}*/

	for (i = 0; i < pow(squareNum, 2); i++) {

		if (i % squareNum == 0) {
			cout << endl;
		}

		cout << setw(digitNumMax) << left << arr.back();
		arr.pop_back();
	}

	return 0;
}





/* 

Gives us input


Output


If it is missing at least one number: "Not all expected numbers are present"

If the rows do not agree: "Row sums differ"

If the columns do not agree: "Column sums differ"

If the diagonals do not agree: "Diagonal sums differ"

If it is a magic square: "The given matrix is a magic square"
*/