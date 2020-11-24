#include <iostream>
using namespace std;

int e, f, c, ans;

int main() {
	cin >> e >> f >> c;
	e += f;
	while (e + (e / c) >= c) {
		int m = e / c;
		int r = e % c;
		ans += m;
		e = r + m;
	}
	cout << ans << '\n';
}