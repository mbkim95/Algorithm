#include <iostream>
using namespace std;

int main() {
	int t, n, m;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		cout << 2 * m - n << ' ' << n - m << '\n';
	}
	return 0;
}