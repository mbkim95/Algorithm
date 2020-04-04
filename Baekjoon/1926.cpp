#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> paint;
vector<vector<bool>> visited;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

int dfs(int x, int y) {
	int cnt = 0;
	int v = paint[y][x];
	visited[y][x] = true;
	stack<pair<int, int>> s;
	s.push({ x, y });

	while (!s.empty()) {
		pair<int, int> cur = s.top();
		s.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second+ dy[i];
			if (inRange(nx, ny) && !visited[ny][nx] && paint[ny][nx] == v) {
				s.push({ nx, ny });
				visited[ny][nx] = true;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int paint_cnt = 0;
	int max_paint = 0;
	paint = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> paint[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && paint[i][j] != 0) {
				max_paint = max(max_paint, dfs(j, i));
				paint_cnt++;
			}
		}
	}
	cout << paint_cnt << '\n' << max_paint << '\n';
	return 0;
}