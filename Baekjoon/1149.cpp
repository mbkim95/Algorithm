#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, h[1000][3], dp[1000][3];

int solve(int cnt, int idx) {
	if (cnt == n)
		return 0;	

	int& ret = dp[cnt][idx];

	if (ret != -1)
		return ret;

	ret = 987654321;

	for (int i = 0; i < 3; i++)
		if (idx != i)
			ret = min(ret, h[cnt][idx] + solve(cnt + 1, i));

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++)
			cin >> h[i][j];
	}
	memset(dp, -1, sizeof(dp));
	int ans = 987654321;

	for (int i = 0; i < 3; i++)
		ans = min(ans, solve(0, i));
	cout << ans << '\n';	
}