#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int box[1001];
int dp[1001];

int solve(int idx) {
	int& ret = dp[idx];
	
	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = idx + 1; i < n; i++) {
		if (box[idx] < box[i]) {
			ret = max(ret, 1 + solve(i));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) 
		cin >> box[i];

	for (int i = 0; i < n; i++)
		solve(i);

	int ans = 0;
	for (int i = 0; i < n; i++) 
		ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}