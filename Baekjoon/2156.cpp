#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, w[10001], dp[10001];

int solve(int idx) {
	if (idx < 0)
		return 0;
	int& ret = dp[idx];

	if (ret != -1)
		return ret;

	ret = max(max(solve(idx - 1), solve(idx - 3) + w[idx - 1] + w[idx]), solve(idx - 2) + w[idx]);		
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	memset(dp, -1, sizeof(dp));
	dp[0] = w[0];
	dp[1] = w[0] + w[1];
	cout << solve(n-1) << '\n';	
	return 0;
}