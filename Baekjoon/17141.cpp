#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

bool isFinished(vector<vector<int>>& map, vector<vector<bool>>& visited) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1)
				continue;
			if (!visited[i][j])
				return false;
		}
	}
	return true;
}

int bfs(vector<vector<int>>& map, vector<pair<int, int>>& cand) {
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>>q;
	for (int i = 0; i < cand.size(); i++) {
		q.push(cand[i]);
		visited[cand[i].second][cand[i].first] = true;
	}

	int time = 0;
	while (!q.empty()) {
		int size = q.size();
		if (isFinished(map, visited)) {
			return time;
		}
		while (size--) {
			pair<int, int>here = q.front();
			q.pop();

			int x = here.first;
			int y = here.second;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (inRange(nx, ny) && !visited[ny][nx] && map[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
		time++;
	}
	return -1;
}

void dfs(vector<vector<int>>& map, vector<pair<int, int>>& v, vector<pair<int, int>>& cand, vector<bool>& sel, int cnt, int idx) {
	if (cnt == m) {
		int tmp = bfs(map, cand);
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
			cand.push_back(v[i]);
			dfs(map, v, cand, sel, cnt + 1, i);
			cand.pop_back();
			sel[i] = false;
		}
	}
}

void solve(vector<vector<int>>& map, vector<pair<int, int>>& v) {
	ans = -1;
	vector<bool> sel(v.size(), false);
	vector<pair<int, int>> cand;
	dfs(map, v, cand, sel, 0, 0);
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
			if (map[i][j] == 2) {
				v.push_back(make_pair(j, i));
				map[i][j] = 0;
			}
		}
	solve(map, v);
	cout << ans << '\n';
	return 0;
}