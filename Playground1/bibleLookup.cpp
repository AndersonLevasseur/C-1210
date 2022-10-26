#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int stringToNumConvert(string userString) {
	int output = 0;
	int n = 0;
	int i = 0;
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
	return output;
}


string CapitalizeString(string inputStr)
{
	char targetChar;
	vector <char> charStr;
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
	return inputStr;
}

int main() {

	string bookName;
	string chapter;
	string verse;
	string line;

	//is there a spelling error?
	bool bookFound = false;
	bool chapterFound = false;
	bool verseFound = false;

	ifstream fin;
	ofstream fout;

	int verseDigNum = 0;

	fin.open("Bible.txt");

	if (fin.fail()) {
		throw "Error with fin";
		cout << "Error with fin";
	}

	fout.open("verses.txt", ios::app);

	if (fout.fail()) {
		cout << "Error with fout";
	}

	cout << "Please enter book name\n";
	getline(cin, bookName, '\n');

	bookName = CapitalizeString(bookName);

	cout << "\014Please enter chapter number\n";
	cin >> chapter;

	cout << "\014Please enter verse number\n";
	cin >> verse;

	while (!fin.eof() && !bookFound) {
		getline(fin, line, '\n');
		if (line.substr(0, 11) == "THE BOOK OF" && line.substr(12, line.length()) == bookName || bookFound) {
			bookFound = true;
		}
	}

	if (bookFound) {
		int chapterDigNum = 0;
		int chapterNum = stringToNumConvert(chapter);
		while (chapterNum > 0) {
			chapterDigNum++;
			chapterNum = chapterNum / 10;
		}
		while (!fin.eof() && !chapterFound) {
		getline(fin, line, '\n');
			if (line.substr(0, 7) == "CHAPTER" || line.substr(0, 5) == "PSALM" || chapterFound) {
				int i;
				if (line.substr(0, 5) == "PSALM") {
					i = 6;
				}
				else {
					i = 8;
				}
				if (line.substr(i, chapterDigNum + i) == chapter) {
					chapterFound = true;
				}
			}
			else if (line.substr(0, 11) == "THE BOOK OF") {
				chapterFound = false;
				break;
			}
		}
	}
	else {
		cout << "book not found\n";
		cout << "you entered : " << bookName << endl;
	}

	if (chapterFound) {
		int verseNum = stringToNumConvert(verse);
		while (verseNum > 0) {
			verseDigNum++;
			verseNum = verseNum / 10;
		}
		while (!fin.eof() && !verseFound) {
			std::getline(fin, line, '\n');
			if (line.substr(0, verseDigNum) == verse || verseFound) {
				verseFound = true;
			}
			else if (line.substr(0, 11) == "THE BOOK OF") {
				chapterFound = false;
			}
		}
	}
	else {
		cout << "chapter not found\n";
		cout << "you entered : " << chapter << endl;
		}

	if (verseFound)
	{
		cout << bookName << " " << chapter << ":" << verse << endl;
		cout << line.substr(verseDigNum) << endl << endl;
		fout << line.substr(verseDigNum);
	}
	else {
		cout << "verse not found\n";
		cout << "you entered : " << verse;

	}
	
	
		return 0;
}