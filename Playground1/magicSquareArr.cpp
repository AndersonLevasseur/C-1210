#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	int squareNum = 0;
	int arrLength = 0;


	cin >> squareNum;
	int digitNumMax = 0;
	int squareArr[5][5];

	int previousRowTotal = 0;
	int colTotal[5] = { 0, 0, 0, 0, 0 };
	int colCompNum;
	int diagCompNum;
	int diagTotal[2] = { 0, 0 };
	int bubbleSort = 1;
	int numCheck[25] = { 0 };

	bool colComp = true;
	bool rowComp = true;
	bool diagComp = true;
	bool numPresent = true;



	for (int i = 0; i < squareNum; i++) {
		int rowTotal = 0;
		for (int j = 0; j < squareNum; j++) {
			int tempNum;

			cin >> tempNum;

			squareArr[i][j] = tempNum;

			numCheck[squareNum * i + j] = tempNum;
			//add number to get rowTotal
			rowTotal += tempNum;

			//add number to get colTotal
			int colTotalNum;
			colTotalNum = colTotal[j];
			colTotalNum += tempNum;
			colTotal[j] = colTotalNum;

			//add number to get daigTotal
			if (i == j) {
				int diagTotalNum = diagTotal[0];
				diagTotalNum += tempNum;
				diagTotal[0] = diagTotalNum;
			}
			else if (i + j == squareNum - 1) {
				int diagTotalNum = diagTotal[1];
				diagTotalNum += tempNum;
				diagTotal[1] = diagTotalNum;
			}

			arrLength++;
		}

		// check if rowTotal = other rowTotals
		if (rowTotal != previousRowTotal && i != 0) {
			rowComp = false;
		}
		previousRowTotal = rowTotal;
	}

	// check if colTotal = other colTotals
	// has to be outside because they don't all finish til for loop is over

	colCompNum = colTotal[0];
	for (int i = 0; i < squareNum; i++) {
		if (colTotal[i] != colCompNum) {
			colComp = false;
		}
	}

	if (diagTotal[0] != diagTotal[1]) {
		diagComp = false;
	}
	// bubble sort to sort arr
// have to see if 1 - squarenum exists in arr
	while (bubbleSort > 0) {
		bubbleSort = 0;
		for (int i = 1; i < (squareNum * squareNum); i++) {
			if (numCheck[i] < numCheck[i-1]) {
				int currentNum = numCheck[i];
				numCheck[i] = numCheck[i - 1];
				 numCheck[i-1] = currentNum;
				bubbleSort++;
			}
			
		}
	}

	// check if all numbers exist
	for (int i = 0; i < (squareNum * squareNum); i++) {
		cout << i << " " << numCheck[i] << endl;
		if (numCheck[i] != i+1) {
			numPresent = false;
		}

	}
	//check if it works
	if (squareNum * squareNum != arrLength) {
		cout << "Not all expected numbers are present";
	}
	else if (!numPresent) {
		cout << "Not all expected numbers are present";
	}
	else if (!rowComp) {
		cout << "Row sums differ";
	}
	else if (!colComp) {
		cout << "Column sums differ";
	}
	else if (!diagComp) {
		cout << "Diagonal sums differ";
	}
	else {
		cout << "The given matrix is a magic square";
	}

	return 0;
}

