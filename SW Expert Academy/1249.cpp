#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> map, cache, visited;
queue<pair<int, int>> q;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void bfs() {
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while (!q.empty()) {
		pair<int, int> here = q.front();
		q.pop();
		int x = here.first;
		int y = here.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (inRange(nx, ny) && (!visited[ny][nx] || cache[ny][nx] > cache[y][x] + map[ny][nx])) {
				cache[ny][nx] = cache[y][x] + map[ny][nx];
				q.push(make_pair(nx, ny));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {	
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		scanf("%d", &n);
		map = vector<vector<int>>(n, vector<int>(n));
		cache = vector<vector<int>>(n, vector<int>(n, 0));
		visited = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		bfs();
		printf("#%d %d\n", c, cache[n - 1][n - 1]);		
	}
	return 0;
}