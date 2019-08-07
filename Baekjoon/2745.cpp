#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int changeValue(char c) {
	int ret;
	if (c == '0')
		ret = 0;
	else if (c == '1')
		ret = 1;
	else if (c == '2')
		ret = 2;
	else if (c == '3')
		ret = 3;
	else if (c == '4')
		ret = 4;
	else if (c == '5')
		ret = 5;
	else if (c == '6')
		ret = 6;
	else if (c == '7')
		ret = 7;
	else if (c == '8')
		ret = 8;
	else if (c == '9')
		ret = 9;
	else if (c == 'A')
		ret = 10;
	else if (c == 'B')
		ret = 11;
	else if (c == 'C')
		ret = 12;
	else if (c == 'D')
		ret = 13;
	else if (c == 'E')
		ret = 14;
	else if (c == 'F')
		ret = 15;
	else if (c == 'G')
		ret = 16;
	else if (c == 'H')
		ret = 17;
	else if (c == 'I')
		ret = 18;
	else if (c == 'J')
		ret = 19;
	else if (c == 'K')
		ret = 20;
	else if (c == 'L')
		ret = 21;
	else if (c == 'M')
		ret = 22;
	else if (c == 'N')
		ret = 23;
	else if (c == 'O')
		ret = 24;
	else if (c == 'P')
		ret = 25;
	else if (c == 'Q')
		ret = 26;
	else if (c == 'R')
		ret = 27;
	else if (c == 'S')
		ret = 28;
	else if (c == 'T')
		ret = 29;
	else if (c == 'U')
		ret = 30;
	else if (c == 'V')
		ret = 31;
	else if (c == 'W')
		ret = 32;
	else if (c == 'X')
		ret = 33;
	else if (c == 'Y')
		ret = 34;
	else if (c == 'Z')
		ret = 35;	
	return ret;
}

int main() {
	int b;
	string str;
	cin >> str >> b;
	int ans = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		ans += (changeValue(str[i]) * pow(b, str.length() - 1 - i));
	}
	cout << ans << '\n';
	return 0;
}