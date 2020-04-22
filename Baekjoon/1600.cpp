#include <iostream>
#include <queue>
using namespace std;

struct monkey {
	int x, y, cnt, k_cnt;
};

int k, w, h;
int map[201][201];
bool visited[201][201][31];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
const int h_dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 }, h_dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int bfs() {
	queue<monkey> q;
	q.push({ 1, 1, 0, 0});
	visited[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int k_cnt = q.front().k_cnt;
		if (x == w && y == h) return cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > w || ny < 1 || ny > h || map[ny][nx] == true || visited[ny][nx][k_cnt] == true) continue;
			visited[ny][nx][k_cnt] = true;
			q.push({ nx, ny, cnt + 1, k_cnt });
		}

		if (k_cnt == k) continue;

		for (int i = 0; i < 8; i++) {
			int nx = x + h_dx[i];
			int ny = y + h_dy[i];
			if (nx < 1 || nx > w || ny < 1 || ny > h || map[ny][nx] == true || visited[ny][nx][k_cnt+1] == true) continue;
			visited[ny][nx][k_cnt+1] = true;
			q.push({ nx, ny, cnt + 1, k_cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	cin >> w >> h;
	for (int i = 1; i <= h; i++) 
		for (int j = 1; j <= w; j++)
			cin >> map[i][j];
	cout << bfs() << '\n';
	return 0;
}