#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int>> tree, cache;
const int dx[] = { -1, 0, 1 ,0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int dfs(int x, int y, int cnt) {
	int& ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx, ny) && tree[ny][nx] < tree[y][x])
			ret = max(ret, dfs(nx, ny, cnt + 1) + 1);
	}
	return ret;
}

void solve() {
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			ans = max(ans , dfs(j, i, 1));
		}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	tree = vector<vector<int>>(n, vector<int>(n));
	cache = vector<vector<int>>(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> tree[i][j];
	solve();
	return 0;
}