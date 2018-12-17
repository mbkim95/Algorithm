#include <iostream>
#include <string>
using namespace std;

int selectCharacter(char c) {
	if (c == 'A' || c == 'B' || c == 'C')
		return 2;
	if (c == 'D' || c == 'E' || c == 'F')
		return 3;
	if (c == 'G' || c == 'H' || c == 'I')
		return 4;
	if (c == 'J' || c == 'K' || c == 'L')
		return 5;
	if (c == 'M' || c == 'N' || c == 'O')
		return 6;
	if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
		return 7;
	if (c == 'T' || c == 'U' || c == 'V')
		return 8;
	if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
		return 9;
}

int main() {
	string str;
	cin >> str;
	int t = str.length();

	for (int i = 0; i < str.length(); i++)
		t += selectCharacter(str[i]);
	
	cout << t << endl;
} 