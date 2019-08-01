#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int board[501][501], chk[501][501];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

int dfs(int x, int y) {
	int& ret = chk[y][x];

	if (ret != -1)
		return chk[y][x];

	if (!inRange(x, y))
		return 0;

	if (x == 0 && y == 0)
		return 1;

	ret = 0;

	for (int i = 0; i<4; i++) {
		if (board[y][x] < board[y + dy[i]][x + dx[i]]) {
			ret += dfs(x + dx[i], y + dy[i]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			cin >> board[i][j];

	memset(chk, -1, sizeof(chk));
	cout << dfs(m - 1, n - 1) << endl;
}