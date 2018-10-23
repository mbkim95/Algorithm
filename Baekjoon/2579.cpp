#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, s[301], dp[301];

int solve(int floor) {
	if (floor <= 0)
		return 0;	

	int& ret = dp[floor];

	if (ret != -1)
		return ret;

	ret = max(solve(floor-3) + s[floor-1] + s[floor], solve(floor-2) + s[floor]);
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';
}