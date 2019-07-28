#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int c[31][31];

int dp(int n, int m) {
	int& ret = c[m][n];

	if (ret != -1)
		return ret;

	if (m == 1 || n == m || n == 0) {
		ret = 1;
		return ret;
	}
	ret = dp(n - 1, m - 1) + dp(n, m - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	memset(c, -1, sizeof(c));
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << dp(a, b) << '\n';
	}
	return 0;
}