#include <iostream>
using namespace std;

int n, m;
int dp[41];

int main() {
	cin >> n;
	cin >> m;
	int ans = 1;
	int prev = 0;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		ans *= (dp[tmp - prev - 1]);
		prev = tmp;
	}
	ans *= (dp[n - prev]);
	cout << ans << '\n';
}