#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int diff = 'a' - 'A';
	for (int i = 0; i < str.length(); i++) {
		char& c = str[i];
		if ('a' <= c && c <= 'z') c -= diff;
		else c += diff;
	}
	cout << str << '\n';
	return 0;
}