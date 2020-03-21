#include <iostream>
#include <vector>
using namespace std;

int n, cnt;
vector<vector<int>> map;
int hx, hy, tx, ty;
vector<vector<int>> move;

bool inRange(int x, int y) {
	return (1 <= x && x <= n) && (1 <= y && y <= n);
}
// dir
// 0 가로
// 1 대각선
// 2 세로
void dfs(int hx, int hy, int tx, int ty, int dir) {
	if (hx == n && hy == n) {
		cnt++;
		return;
	}

	if (dir == 0) {
		if (inRange(hx + 1, hy) && map[hy][hx + 1] == 0) 
			dfs(hx + 1, hy, tx + 1, ty, 0);
		
		if (inRange(hx + 1, hy + 1) && map[hy][hx + 1] == 0 && map[hy + 1][hx + 1] == 0 && map[hy + 1][hx] == 0)
			dfs(hx + 1, hy + 1, tx + 1, ty, 1);
	}
	else if (dir == 1) {
		if (inRange(hx + 1, hy) && map[hy][hx + 1] == 0)
			dfs(hx + 1, hy, tx + 1, ty + 1, 0);
		if (inRange(hx, hy + 1) && map[hy + 1][hx] == 0)
			dfs(hx, hy + 1, tx + 1, ty + 1, 2);
		if (inRange(hx + 1, hy + 1) && map[hy + 1][hx + 1] == 0 && map[hy + 1][hx] == 0 && map[hy][hx + 1] == 0)
			dfs(hx + 1, hy + 1, tx + 1, ty + 1, 1);
	}
	else if (dir == 2) {
		if (inRange(hx, hy + 1) && map[hy + 1][hx] == 0)
			dfs(hx, hy + 1, tx, ty + 1, 2);
		if (inRange(hx + 1, hy + 1) && map[hy + 1][hx + 1] == 0 && map[hy + 1][hx] == 0 && map[hy][hx + 1] == 0)
			dfs(hx + 1, hy + 1, tx, ty + 1, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(2, 1, 1, 1, 0);
	cout << cnt << '\n';
	return 0;
}