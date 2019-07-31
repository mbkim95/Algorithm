#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c, d, ans;
vector<vector<int>> map;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

int changeDir(int dir) {
	int ret;
	switch (dir) {
	case 0:
		ret = 3;
		break;
	case 1:
		ret = 0;
		break;
	case 2:
		ret = 1;
		break;
	case 3:
		ret = 2;
		break;
	}
	return ret;
}

int backDir(int dir) {
	int ret = dir + 2;
	if (ret >= 4)
		ret -= 4;
	return ret;
}

void solve() {
	int x = c;
	int y = r;
	int dir = d;
	while (true) {
		if (map[y][x] == 0) {
			map[y][x] = 2;
			ans++;
		}
		int nx, ny;
		bool find = false;
		for (int i = 0; i < 4; i++) {
			dir = changeDir(dir);
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (map[ny][nx] == 0) {
				y = ny;
				x = nx;
				find = true;
				break;
			}
		}
		if (!find) {
			dir = backDir(dir);
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (map[ny][nx] == 1)
				break;
			else {
				x = nx;
				y = ny;
				dir = backDir(dir);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	map = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}