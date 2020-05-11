#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
vector<vector<int>> map, tmp;
vector<pair<int, int>> cctv;
int cctv_dir[8];
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

void observe(int x, int y, int dir) {
	int nx = x; int ny = y;

	while (true) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || tmp[ny][nx] == 6) break;
		if (tmp[ny][nx] != 0) continue;
		tmp[ny][nx] = -1;
	}
}

int simulation() {
	tmp = map;
	int ret = 0;

	for (int i = 0; i < cctv.size(); i++) {
		int x = cctv[i].first; int y = cctv[i].second;
		int model = map[y][x];
		observe(x, y, cctv_dir[i]);
		if (model == 2 || model == 4 || model == 5) observe(x, y, (cctv_dir[i] + 2) % 4);
		if (model == 3 || model == 4 || model == 5) observe(x, y, (cctv_dir[i] + 1) % 4);
		if (model == 5) observe(x, y, cctv_dir[i] + 3);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!tmp[i][j]) ret++;
	return ret;
}

void dfs(int cnt) {
	if (cnt == cctv.size()) {
		ans = min(ans, simulation());
		return;
	}

	int x = cctv[cnt].first;
	int y = cctv[cnt].second;
	int& tv = map[y][x];

	for (int i = 0; i < 4; i++) {
		if(tv == 2 && (i == 2 || i == 3)) continue;
		if (tv == 5 && i > 0) continue;
		cctv_dir[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	ans = m * n;
	map = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				cctv.push_back({ j, i });
		}
	dfs(0);
	cout << ans << '\n';
	return 0;
}