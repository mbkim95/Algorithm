#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, cnt;
vector<int> ans;
vector<vector<int>> map;
const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void setSquare(int x1, int y1, int x2, int y2) {
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			map[i][j] = 1;
		}
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

void dfs(int x, int y) {
	map[y][x] = 2;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inRange(nextX, nextY) && !map[nextY][nextX]) {
			dfs(nextX, nextY);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n >> k;
	map = vector<vector<int>>(m, vector<int>(n, 0));
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		setSquare(x1, y1, x2-1, y2-1);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				dfs(j, i);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << ' ';
	cout << '\n';
	return 0;
}