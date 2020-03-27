#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cheese;
vector<vector<int>> map, chk;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

int bfs(int x, int y) {
	chk = vector<vector<int>>(n, vector<int>(m, 0));
	queue<pair<int, int>> q;
	q.push({ x, y });
	chk[y][x] = 0;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (inRange(nx, ny) && chk[ny][nx] == 0) {
				if (map[ny][nx] == 1) {
					map[ny][nx] = 0;
					cnt++;
				}
				else 
					q.push({ nx, ny });
				
				chk[ny][nx] = 1;
			}
		}
	}
	return cheese - cnt;
}

void solve() {
	int time = 0, prev = cheese;
	while (true) {
		if (cheese == 0)
			break;
		prev = cheese;
		cheese = bfs(0, 0);
		time++;
	}
	cout << time << '\n' << prev << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)  cheese++;
		}
	solve();
	return 0;
}