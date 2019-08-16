#include <iostream>
#include <vector>
using namespace std;

int ans;
vector<vector<int>> board;
vector<bool> chk;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < 4) && (0 <= y && y < 4);
}

void dfs(int x, int y, int cnt, int num) {
	if (cnt == 7) {
		if (!chk[num]) {
			chk[num] = true;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx, ny)) {
			dfs(nx, ny, cnt + 1, num * 10 + board[ny][nx]);
		}
	}
}

void solve() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dfs(j, i, 1, board[i][j]);
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		ans = 0;
		chk = vector<bool>(10000000, false);
		board = vector<vector<int>>(4, vector<int>(4));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> board[i][j];
		solve();
		cout << "#" << c << ' ' << ans << '\n';
	}
	return 0;
}