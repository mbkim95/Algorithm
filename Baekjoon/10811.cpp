#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		reverse(v.begin() + s - 1, v.begin() + e);
	}
	for (auto x : v)
		cout << x << ' ';
	cout << '\n';
	return 0;
}