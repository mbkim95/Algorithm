#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree {
	int x, y, dir, cnt;
};

int n;
char map[50][51];
bool visited[50][50][2];
vector<pair<int, int>> tree, fin;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

// 나무가 회전할 수 있는지 확인
bool can_rotate(int x, int y) {
	if (x - 1 < 0 || x + 1 > n - 1 || y - 1 < 0 || y + 1 > n - 1) return false;
	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + 1; j++)
			if (map[i][j] == '1') return false;
	return true;
}

bool can_move(int x, int y, int dir, int go) {
	// 나무가 가로로 놓여있을 때
	if (dir == 0) {
		// 좌우 방향으로 옮길 때
		if (go == 0 || go == 2) {
			int nx = x + 2 * dx[go];
			if (nx < 0 || nx > n - 1 || map[y][nx] == '1') return false;
		}
		// 상하 방향으로 옮길 때
		else {
			for (int i = -1; i <= 1; i++) {
				int nx = x + i;
				int ny = y + dy[go];
				if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) return false;
				if (map[ny][nx] == '1') return false;
			}
		}
	}
	// 나무가 세로로 놓여있을 때
	else {
		// 상하 방향으로 옮길 때
		if (go == 1 || go == 3) {
			int ny = y + 2 * dy[go];
			if (ny < 0 || ny > n - 1 || map[ny][x] == '1') return false;
		}
		// 좌우 방향으로 옮길 때
		else {
			for (int i = -1; i <= 1; i++) {
				int nx = x + dx[go];
				int ny = y + i;
				if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) return false;
				if (map[ny][nx] == '1') return false;
			}
		}
	}
	return true;
}

int bfs() {
	Tree f;
	f.x = fin[1].first; f.y = fin[1].second; f.cnt = 0;
	// 목적지의 x값이 바뀌면 세로
	if (fin[0].first != fin[1].first) f.dir = 0;
	// 목적지의 x값이 모두 같으면 가로
	else f.dir = 1;

	Tree t;
	t.x = tree[1].first; t.y = tree[1].second; t.cnt = 0;
	// 나무의 x값이 바뀌면 세로
	if (tree[0].first != tree[1].first) t.dir = 0;
	// 나무의 x값이 바뀌면 세로
	else t.dir = 1;

	queue<Tree> q;
	q.push(t);
	visited[t.y][t.x][t.dir] = true;

	while (!q.empty()) {
		Tree cur = q.front();
		if (cur.x == f.x && cur.y == f.y && cur.dir == f.dir) return cur.cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
			if (!visited[ny][nx][cur.dir] && can_move(cur.x, cur.y, cur.dir, i)) {
				visited[ny][nx][cur.dir] = true;
				q.push({ nx, ny, cur.dir, cur.cnt + 1 });
			}
		}

		if (!visited[cur.y][cur.x][!cur.dir] && can_rotate(cur.x, cur.y)) {
			visited[cur.y][cur.x][!cur.dir] = true;
			q.push({ cur.x, cur.y, !cur.dir, cur.cnt + 1 });
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
            // 나무의 좌표 저장
			if (map[i][j] == 'B') tree.push_back({ j, i });
            // 목적지의 좌표 저장
			else if (map[i][j] == 'E') fin.push_back({ j, i });
		}
	cout << bfs() << '\n';
	return 0;
}