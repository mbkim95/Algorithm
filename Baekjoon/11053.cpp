#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001], dp[1001];

int solve(int cur) {
	int& ret = dp[cur];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = cur + 1; i < n; i++) {
		if (arr[cur] < arr[i])
			ret = max(ret, solve(i) + 1);
	}
	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans = max(ans, solve(i));
	}
	cout << ans << endl;
}