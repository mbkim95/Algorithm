#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[500][500];
bool chk[500][500];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

int dfs(int x, int y, int cnt) {
	if (cnt == 4)
		return board[y][x];

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!chk[ny][nx] && (0 <= nx && nx < m) && (0 <= ny && ny < n)) {
			chk[ny][nx] = true;
			ret = max(ret, dfs(nx, ny, cnt + 1) + board[y][x]);			
			chk[ny][nx] = false;
		}
	}
	return ret;
}

int exceptShape(int x, int y) {
	int ret = 0;

	// っ
	if ((1 <= x && x < m) && (1 <= y && y < n - 1))
		ret = board[y][x] + board[y][x - 1] + board[y + 1][x] + board[y - 1][x];
	// た
	if ((0 <= x && x < m - 1) && (1 <= y && y < n - 1))
		ret = max(ret, board[y][x] + board[y][x + 1] + board[y + 1][x] + board[y - 1][x]);
	// で
	if ((1 <= x && x < m - 1) && (1 <= y && y < n - 1))
		ret = max(ret, board[y][x] + board[y][x + 1] + board[y - 1][x] + board[y][x - 1]);
	// ぬ
	if ((1 <= x && x < m - 1) && (0 <= y && y < n - 1))
		ret = max(ret, board[y][x] + board[y][x + 1] + board[y][x - 1] + board[y + 1][x]);

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chk[i][j] = true;
			ans = max(ans, dfs(j, i, 1));
			ans = max(ans, exceptShape(j, i));
			chk[i][j] = false;
		}
	}
	cout << ans << '\n';
}