#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		cout << (a / g) * b << ' ' << g << '\n';
	}
	return 0;
}