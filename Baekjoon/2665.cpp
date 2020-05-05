#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int map[51][51];
vector<vector<int>> visited;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void bfs() {
	visited = vector<vector<int>>(n + 1, vector<int>(n + 1, 987654321));
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (map[ny][nx] == 0 && visited[ny][nx] > visited[y][x] + 1) {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ nx, ny });
			}
			else if (map[ny][nx] == 1 && visited[ny][nx] > visited[y][x]) {
				visited[ny][nx] = visited[y][x];
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);

	bfs();
	printf("%d\n", visited[n][n]);
	return 0;
}