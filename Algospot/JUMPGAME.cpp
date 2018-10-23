#include <iostream>
#include <cstring>
using namespace std;

int n, b[100][100], dp[100][100];

int jump(int x, int y) {
	if (x > n - 1 || y > n - 1)
		return 0;
	if (x == n - 1 && y == n - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = jump(x + b[y][x], y) || jump(x, y + b[y][x]);

	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));
		int ans = jump(0, 0);

		if (ans == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}