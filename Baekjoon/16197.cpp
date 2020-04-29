#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Coins {
	int x1, y1, x2, y2, cnt;
};

int n, m, cx1, cy1, cx2, cy2;
char map[20][20];
bool visited[20][20][20][20];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

int bfs() {
	queue<Coins> q;
	q.push({ cx1, cy1, cx2, cy2, 0 });
	visited[cy1][cx1][cy2][cx2] = true;

	while (!q.empty()) {
		Coins cur = q.front();
		q.pop();

		if (cur.cnt > 10) break;

		for (int i = 0; i < 4; i++) {
			int nx1 = cur.x1 + dx[i]; int ny1 = cur.y1 + dy[i];
			int nx2 = cur.x2 + dx[i]; int ny2 = cur.y2 + dy[i];
			if ((inRange(nx1, ny1) && !inRange(nx2, ny2)) || (!inRange(nx1, ny1) && inRange(nx2, ny2))) {
				if (cur.cnt + 1 > 10) return -1;
				return cur.cnt + 1;
			}
			if (!inRange(nx1, ny1) && !inRange(nx2, ny2)) continue;
			if (map[ny1][nx1] == '#') {
				nx1 -= dx[i]; ny1 -= dy[i];
			}
			if (map[ny2][nx2] == '#') {
				nx2 -= dx[i]; ny2 -= dy[i];
			}
			if (!visited[ny1][nx1][ny2][nx2]) {
				q.push({ nx1, ny1, nx2, ny2, cur.cnt + 1 });
				visited[ny1][nx1][ny2][nx2] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	bool first = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				if (first) {
					cx1 = j; cy1 = i;
					first = false;
				}
				else {
					cx2 = j; cy2 = i;
				}
			}
		}
	cout << bfs() << '\n';
	return 0;
}