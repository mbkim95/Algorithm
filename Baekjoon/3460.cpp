#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, tmp = 0x01;
		cin >> n;
		for (int i = 0; i < 32; i++) {
			if (n & tmp) cout << i << ' ';
			tmp <<= 1;
		}
		cout << '\n';
	}
	return 0;
}