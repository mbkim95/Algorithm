#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c, ans = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		sum = 0;
		cin >> a >> b >> c;
		if (a == b && b == c) sum += (10000 + a * 1000);
		else if (a == b || b == c || a == c) {
			if(a == b || a == c) sum += (1000 + a * 100);
			if(b == c) sum += (1000 + c * 100);			
		}
		else {
			int m = max(a, max(b, c));
			sum += 100 * m;
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
	return 0;
}