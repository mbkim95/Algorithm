#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int t[1001], dp[1001];
int r[1001][1001];

void reset() {
	memset(dp, -1, sizeof(dp));
	memset(r, 0, sizeof(r));
}

int solve(int cur) {
	int& ret = dp[cur];

	if (ret != -1)
		return ret;

	int time = 0;

	for (int i = 1; i <= n; i++) {
		if (r[i][cur]) {
			time = max(time, solve(i));
		}
	}
	return ret = t[cur] + time;
}

int main() {
	int c, k, w;
	cin >> c;
	while (c--) {
		reset();
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t[i]);
		}

		for (int i = 1; i <= k; i++) {
			int tmp1, tmp2;
			scanf("%d %d", &tmp1, &tmp2);
			r[tmp1][tmp2] = 1;
		}
		scanf("%d", &w);
		printf("%d\n", solve(w));
	}
	return 0;
}