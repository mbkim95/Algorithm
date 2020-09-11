#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

long long x, y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> y;

	int left = 1;
	int right = 1000000000;
	int ans = numeric_limits<int>::max();
	int z = (y * 100) / x;

	while (left <= right) {
		int mid = (left + right) / 2;

		int tmp_z = ((y + mid) * 100) / (x + mid);
		if (z < tmp_z) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}

	if (ans == numeric_limits<int>::max()) cout << -1 << '\n';
	else cout << ans << '\n';
	return 0; 
}