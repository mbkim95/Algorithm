#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, int> m = {
		{"black", 0}, {"brown", 1}, {"red", 2},
		{"orange", 3}, {"yellow", 4}, {"green", 5},
		{"blue", 6}, {"violet", 7}, {"grey", 8},
		{"white", 9}
	};
	string a, b, c;
	cin >> a >> b >> c;

	long long ans = m[a] * 10 + m[b];
	int end = m[c];

	for (int i = 0; i < end; i++) {
		ans *= 10;
	}
	cout << ans << '\n';
}