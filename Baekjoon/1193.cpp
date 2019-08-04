#include <iostream>
using namespace std;

int x;

int getStart() {
	int ret = 1;
	while (ret * (ret + 1) <= 2 * x) {
		if (ret * (ret + 1) == 2 * x)
			break;
		ret++;
	}
	return ret;
}

void solve() {
	int g = getStart();
	int a, b;
	int pos = x - ((g - 1)*g / 2);
	if (g % 2) {
		a = g + 1 - pos;
		b = pos;
	}
	else {
		a = pos;
		b = g + 1 - pos;
	}
	cout << a << '/' << b << '\n';
}

int main() {
	cin >> x;
	solve();
	return 0;
}