#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t[16], p[16], dp[16];
int n;

int solve(int idx) {
	if (idx == n+1)
		return 0;

	if (idx > n + 1)
		return -987654321;

	if (dp[idx] != -1)
		return dp[idx];

	dp[idx] = max(solve(idx+1), solve(idx + t[idx]) + p[idx]);

	return dp[idx];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];

	memset(dp, -1, sizeof(dp));
	
	cout << solve(1) << '\n';

	return 0;
}