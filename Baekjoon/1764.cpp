#include <iostream>
#include <map>
using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	map<string, int> d;

	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		d[str]++;
	}
	for (int i = 1; i <= m; i++) {
		string str;
		cin >> str;
		d[str]++;
	}

	int ans = 0;
	for (auto p : d) {
		if (p.second == 2)
			ans++;
	}

	cout << ans << '\n';

	for (auto p : d) {
		if (p.second == 2) {
			cout << p.first << '\n';
		}
	}
}