#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, dp[10000001];

int solve(int num) {
	if (num == 1)
		return 0;

	int& ret = dp[num];

	if (ret != -1)
		return ret;

	ret = 987654321;

	if (num % 3 == 0)
		ret = min(ret, solve(num / 3) + 1);

	if (num % 2 == 0)
		ret = min(ret, solve(num / 2) + 1);

	ret = min(ret, solve(num - 1) + 1);
	return ret;
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';
}