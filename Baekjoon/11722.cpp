#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, dp;

int solve(int idx) {
	int& ret = dp[idx];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = idx + 1; i < n; i++) {
		if (arr[idx] > arr[i]) {
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
	arr = vector<int>(n);
	dp = vector<int>(n, -1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		solve(i);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
	return 0;
}