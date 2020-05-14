#include <iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c;
	cin >> d;
	c += d;
	b += c / 60, c %= 60;
	a += b / 60, b %= 60;
	a %= 24;
	cout << a << ' ' << b << ' ' << c << '\n';
	return 0;
}