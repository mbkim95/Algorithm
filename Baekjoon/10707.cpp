#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;

	int ans = min(a * p, b + (p - c > 0 ? (p - c) * d : 0));
	cout << ans << '\n';
	return 0;
}