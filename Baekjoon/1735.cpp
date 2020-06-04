#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a1, a2, b1, b2;
	cin >> a1 >> b1;
	cin >> a2 >> b2;
	int lcm = b1 * b2 / gcd(b1, b2);
	int child1 = a1 * (lcm / b1);
	int child2 = a2 * (lcm / b2);
	int child = child1 + child2;
	int g = gcd(child, lcm);
	if (g == 1) cout << child << ' ' << lcm << '\n';
	else cout << child / g << ' ' << lcm / g << '\n';
	return 0;
}