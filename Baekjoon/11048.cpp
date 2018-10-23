#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int b[1001][1001], dp[1001][1001];
int dx[3] = { 0, 1, 1 }, dy[3] = { 1, 0, 1 };

int solve(int y, int x) {
	if (y > n || x > m)
		return 0;

	int& ret = dp[y][x];

	if(ret != -1)
		return ret;

	for (int i = 0; i < 3; i++) {
		ret = max(ret, solve(y + dy[i], x + dx[i]) + b[y][x]);
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1) << '\n';
}