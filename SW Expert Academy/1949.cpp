#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, ans;
vector<vector<int>> m;
vector<vector<bool>> visited;
vector<pair<int, int>>p;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void getStartPoint(int value) {
	p.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (value == m[i][j])
				p.push_back(make_pair(j, i));
		}
	}
}

void dfs(int x, int y, int cnt, bool isWorked) {
	bool isEnd = true;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inRange(nx, ny) || visited[ny][nx])
			continue;

		if (m[y][x] > m[ny][nx]) {
			dfs(nx, ny, cnt + 1, isWorked);
			isEnd = false;
		}
		else if (!isWorked && m[y][x] > m[ny][nx] - k) {
			int tmp = m[ny][nx];
			m[ny][nx] = m[y][x] - 1;
			dfs(nx, ny, cnt + 1, true);
			isEnd = false;
			m[ny][nx] = tmp;
		}		
	}
	if (isEnd)
		if (ans < cnt) {
			ans = cnt;
		}
	visited[y][x] = false;
}

void solve() {
	ans = 0;
	visited = vector<vector<bool>>(n, vector<bool>(n, false));
	for (int i = 0; i < p.size(); i++) {
		dfs(p[i].first, p[i].second, 1, false);
	}
}

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> n >> k;
		m = vector<vector<int>>(n, vector<int>(n));
		int maxPoint = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
				maxPoint = max(maxPoint, m[i][j]);
			}
		}
		getStartPoint(maxPoint);
		solve();
		cout << '#' << c << ' ' << ans << '\n';
	}
	return 0;
}