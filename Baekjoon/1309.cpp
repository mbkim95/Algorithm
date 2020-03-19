#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[100001];

int solve(int idx) {
	int& ret = dp[idx];
	if (ret != -1) return ret;

	if (idx == 1)
		return ret = 3;
	
	if (idx == 2)
		return ret = 7;

	return ret = (2 * solve(idx - 1) + solve(idx - 2)) % 9901;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';
	return 0;
}