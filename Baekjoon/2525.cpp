#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	cin >> c;

	b += c;
	if (b >= 60) {
		a += (b / 60);
		b = b % 60;
	}

	if (a >= 24) {
		a -= 24;
	}
	cout << a << ' ' << b << '\n';
	return 0;
}