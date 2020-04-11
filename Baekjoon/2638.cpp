#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, cnt;
int map[101][101], visited[101][101];
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void checkOutline() {
	for (int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1) continue;
			if (map[ny][nx] == 1) visited[ny][nx]++;
			if (visited[ny][nx] == 0 && map[ny][nx] == 0) {
				q.push({ nx, ny });
				visited[ny][nx] = 1;
			}
		}
	}
}

void removeCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] > 1) {
				map[i][j] = 0;
				cnt--;
			}
		}
	}
}

int solve() {
	int time = 0;
	while (cnt > 0) {
		checkOutline();
		removeCheese();
		time++;
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cnt++;
		}
	}
	cout << solve() << '\n';
	return 0;
}