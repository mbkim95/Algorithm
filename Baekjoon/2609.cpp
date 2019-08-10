#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int gcd = 1;
	int div = 2;
	while (div <= a && div <= b) {
		if (a % div == 0 && b % div == 0) {
			gcd *= div;
			a /= div;
			b /= div;
		}
		else {
			div++;
		}
	}
	cout << gcd << '\n' << a * b * gcd << '\n';
	return 0;
}