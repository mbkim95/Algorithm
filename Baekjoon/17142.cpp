#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, chk, ans;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int bfs(vector<vector<int>>& map, vector<pair<int, int>>& v, vector<bool>& sel) {
	int cnt = 0;
	vector<vector<int>> visited(n, vector<int>(n, -1));
	queue<pair<int, int>>q;
	for (int i = 0; i < v.size(); i++) {
		if (sel[i]) {
			q.push(v[i]);
			visited[v[i].second][v[i].first] = 0;
		}
	}
	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			pair<int, int>here = q.front();
			q.pop();

			int x = here.first;
			int y = here.second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (inRange(nx, ny) && visited[ny][nx] == -1 && map[ny][nx] != 1) {
					visited[ny][nx] = visited[y][x] + 1;
					if (map[ny][nx] == 0) {
						time = visited[ny][nx];
						cnt++;
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (cnt == chk) {
		return time;
	}
	return -1;
}

void dfs(vector<vector<int>>& map, vector<pair<int, int>>& v, vector<bool>& sel, int cnt, int idx) {
	if (cnt == m) {
		int tmp = bfs(map, v, sel);
		if (tmp != -1)
			if (ans == -1)
				ans = tmp;
			else
				ans = min(ans, tmp);
		return;
	}

	if (idx == v.size())
		return;

	for (int i = idx; i < v.size(); i++) {
		if (!sel[i]) {
			sel[i] = true;
			dfs(map, v, sel, cnt + 1, i);
			sel[i] = false;
		}
	}
}

void solve(vector<vector<int>>& map, vector<pair<int, int>>& v) {
	ans = -1;
	vector<bool> sel(v.size(), false);
	dfs(map, v, sel, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(n));
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) chk++;
			if (map[i][j] == 2) v.push_back(make_pair(j, i));
		}
	solve(map, v);
	cout << ans << '\n';
	return 0;
}