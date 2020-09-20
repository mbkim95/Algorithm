#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int zero = 0;
	int one = 0;

	if (s[0] == '0') zero++;
	else one++;

	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != s[i + 1]) {
			if (s[i + 1] == '0') zero++;
			else one++;
		}
	}
	cout << (zero < one ? zero : one) << '\n';
	return 0;
}