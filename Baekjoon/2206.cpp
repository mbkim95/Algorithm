#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct POINT{
	int crash, x, y;
};

int n, m;
vector<vector<vector<int>>> map, visited;

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

int bfs() {
	queue<POINT> q;
	POINT p = { 0, 0, 0};
	q.push(p);
	visited[0][0][0] = 1;
	const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
	int distance = 1;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			POINT tmp = q.front();
			q.pop();

			if (tmp.x == m - 1 && tmp.y == n - 1)
				return distance;
			for (int i = 0; i < 4; i++) {
				int nextX = tmp.x + dx[i], nextY = tmp.y + dy[i];
				if (inRange(nextX, nextY) && !visited[tmp.crash][nextY][nextX]) {
					if (map[tmp.crash][nextY][nextX]) {
						if (!tmp.crash) {
							visited[1][nextY][nextX] = 1;
							q.push(POINT{1, nextX, nextY});
						}
					}
					else {
						visited[tmp.crash][nextY][nextX] = 1;
						q.push(POINT{ tmp.crash, nextX, nextY });
					}
				}
			}
		}
		distance++;
	}
	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	map = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(m, 0)));
	visited = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(m, 0)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int tmp;
			scanf("%1d", &tmp);
			map[0][i][j] = map[1][i][j] = tmp;
		}

	printf("%d\n", bfs());
	return 0;
}