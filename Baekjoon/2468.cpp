#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> h;
vector<vector<int>> visited;
const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void dfs(int x, int y, int height) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inRange(nextX, nextY) && !visited[nextY][nextX] && h[nextY][nextX] > height) {
			dfs(nextX, nextY, height);
		}
	}
}

int main() {
	int max_h = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	h = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			max_h = max(max_h, tmp);
			h[i][j] = tmp;
		}
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i <= max_h; i++) {
		visited = vector<vector<int>>(n, vector<int>(n, 0));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k] && h[j][k] > i) {
					dfs(k, j, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
		cnt = 0;
	}
	cout << ans << '\n';
	return 0;
}