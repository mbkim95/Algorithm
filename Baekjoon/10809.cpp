#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < 26; i++) {
		auto it = find(s.begin(), s.end(), 'a' + i);
		if (it == s.end())
			cout << -1 << ' ';
		else
			cout << it-s.begin() << ' ';
	}
	cout << '\n';
	return 0;
}