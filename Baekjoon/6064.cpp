#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int x, y, m, n;
		cin >> m >> n >> x >> y;
		int ans = 0;
		ans += x;
		int limit = lcm(m, n);
		bool find = false;
		int b = x;
		while (!(1 <= b && b <= n))
			b -= n;
	
		while (ans <= limit) {
			if (b == y) {
				find = true;
				break;
			}
			ans += m;
			b += (m - n);
			if (b < 1) {
				while (!(1 <= b && b <= n))
					b += n;
			}
			else if (b > n)
				while (!(1 <= b && b <= n))
					b -= n;
		}

		if (!find)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}
	return 0;	
}