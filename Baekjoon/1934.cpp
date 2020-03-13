#include <iostream>
using namespace std;

int getGCD(int a, int b) {
	if (b == 0)
		return a;
	return getGCD(b, a % b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		int gcd = a >= b ? getGCD(a, b) : getGCD(b, a);
		cout << a * b / gcd << '\n';
	}
	return 0;
}