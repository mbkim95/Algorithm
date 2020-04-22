#include <iostream>
#include <queue>
using namespace std;

struct robot {
	int x, y, dir, cnt;
};

int n, m;
int sx, sy, sdir, ex, ey, edir;
int map[101][101];
bool visited[101][101][5];
const int dx[] = { 0, 1, -1, 0, 0 }, dy[] = { 0, 0, 0, 1, -1 };

int bfs() {
	int ret = 0;
	queue<robot> q;
	q.push({ sx, sy, sdir, 0 });
	visited[sy][sx][sdir] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		if (x == ex && y == ey && dir == edir) break;
		q.pop();

		// 같은 방향으로 1~3칸 이동
		for (int i = 1; i <= 3; i++) {
			int nx = x + i * dx[dir];
			int ny = y + i * dy[dir];
			
			if (nx < 1 || nx > n || ny < 1 || ny > m) break;
			if (map[ny][nx] == 1) break;
			if (!visited[ny][nx][dir]) {
				visited[ny][nx][dir] = true;
				q.push({ nx, ny, dir, cnt + 1 });
			}
		}

		// 방향 전환
		for (int i = 1; i <= 4; i++) {
			// 같은 방향이거나 이미 방문한 적 있는 경우
			if (i == dir || visited[y][x][i] == true) continue;
			visited[y][x][i] = true; 
			// 반대방향으로 돌리는 경우
			if (dx[i] + dx[dir] == 0 && dy[i] + dy[dir] == 0) q.push({ x, y, i, cnt + 2 });
			// 90도 회전하는 경우
			else q.push({ x, y, i, cnt + 1 });
		}
	}
	return q.front().cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	cin >> sy >> sx >> sdir;
	cin >> ey >> ex >> edir;
	cout << bfs() << '\n';
	return 0;
}	