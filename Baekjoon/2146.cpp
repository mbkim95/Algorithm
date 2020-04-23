#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, ans = 987654321;
int map[101][101];
bool visited[101][101];
vector<pair<int, int>> p;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

void divide_field(int x, int y, int idx) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	map[y][x] = idx;
	visited[y][x] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
			if (map[ny][nx] == -1 && !visited[ny][nx]) {
				map[ny][nx] = idx;
				visited[ny][nx] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int make_bridge(int idx) {
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == idx) {
				visited[i][j] = true;
				q.push({ {j, i}, 0 });
			}
		}
	}
	
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			if (ans < cnt) return 987654321;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
				if (map[ny][nx] != idx && map[ny][nx] != 0) return cnt;
				if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
					q.push({ {nx, ny}, cnt + 1 });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				map[i][j] = -1;
				p.push_back({ j, i });
			}
		}
	
	int idx = 1;
	for (int i = 0; i < p.size(); i++) {
		int x = p[i].first;
		int y = p[i].second;
		if (!visited[y][x]) divide_field(x, y, idx++);
	}

	for (int i = 1; i < idx; i++) 
		ans = min(ans, make_bridge(i));
	cout << ans << '\n';
	return 0;
}