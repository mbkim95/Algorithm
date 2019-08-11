#include <iostream>
using namespace std;

int h, w, n;

int getRange() {
	int i;
	for (i = 1; i <= w; i++) {
		if ((i - 1) * h < n && n <= i * h)
			break;
	}
	return i;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int ho = getRange();
		int floor = n % h;
		if (floor == 0)
			floor = h;
		if (ho < 10) {
			cout << floor << 0 << ho << '\n';
		}
		else {
			cout << floor << ho << '\n';
		}
	}
	return 0;
}