#include <iostream>
using namespace std;

const int MAX = 20 * 52;

int main() {
	bool arr[MAX + 1];
	for (int i = 1; i <= MAX; i++) arr[i] = true;

	for (int i = 2; i * i <= MAX; i++) {
		if (arr[i]) {
			int j = 2;
			while (i * j <= MAX) {
				arr[i * j] = false;
				j++;
			}
		}
	}

	string s;
	int sum = 0;
	cin >> s;
	for (char c : s) {
		if ('a' <= c && c <= 'z') sum += (c - 'a' + 1);
		else sum += (c - 'A' + 27);
	}
	if (arr[sum]) cout << "It is a prime word.\n";
	else cout << "It is not a prime word.\n";
	return 0;
}