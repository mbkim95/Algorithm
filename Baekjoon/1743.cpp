#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int map[101][101];
const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool isRange(int y, int x) {
	return (1 <= x && x <= m) && (1 <= y && y <= n);
}

int dfs(int y, int x) {
	int ret = 1;
	map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (map[nextY][nextX] && isRange(nextY, nextX)) {
			ret += dfs(nextY, nextX);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		map[tmp1][tmp2] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				ans = max(ans, dfs(i, j));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}