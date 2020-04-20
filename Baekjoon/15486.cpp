#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[1500001], m[1500001];
int dp[1500002];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> t[i] >> m[i];

	int ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		ans = max(ans, dp[i]);
		if (i + t[i] <= n + 1) 
			dp[i + t[i]] = max(dp[i + t[i]], ans + m[i]);
	}
	cout << ans << '\n';
	return  0;
}