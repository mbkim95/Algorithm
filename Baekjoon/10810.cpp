#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		fill(v.begin() + a - 1, v.begin() + b, c);
	}
	for (auto x : v)
		cout << x << ' ';
	cout << '\n';
	return 0;
}