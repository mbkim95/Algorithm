#include <iostream>
#include <queue>
using namespace std;

struct minsik {
	int x, y, key, cnt;
};

int n, m, sx, sy;
char map[50][50];
bool visited[50][50][64];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool check_key(int cur_key, char door) {
	if ((cur_key & (1 << (door - 'A'))) == 0) return false;
	return true;
}

int set_key(int cur_key, char value) {
	return cur_key | (1 << (value - 'a'));
}

int bfs() {
	queue<minsik> q;
	q.push({ sx, sy, 0, 0 });
	visited[sy][sx][0] = true;

	while (!q.empty()) {
		minsik cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i]; int ny = cur.y + dy[i];
			if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || visited[ny][nx][cur.key] || map[ny][nx] == '#') continue;
			if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
				if (check_key(cur.key, map[ny][nx])) {
					q.push({ nx, ny, cur.key, cur.cnt + 1 });
					visited[ny][nx][cur.key] = true;
				}
			}
			else if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') {
				int key = set_key(cur.key, map[ny][nx]);
				q.push({ nx, ny, key, cur.cnt + 1 });
				visited[ny][nx][key] = true;
			}
			else if (map[ny][nx] == '1') return cur.cnt + 1;
			else {
				q.push({ nx, ny, cur.key, cur.cnt + 1 });
				visited[ny][nx][cur.key] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				sx = j; sy = i;
			}
		}
	cout << bfs() << '\n';
	return 0;
}