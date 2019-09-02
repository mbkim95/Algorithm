#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int sx, sy, total_ate;
int n, m, ate, cnt, size = 2;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

void print(vector<vector<int>>& map) {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int bfs(vector<vector<int>>& map) {
	vector<vector<int>> chk(n, vector<int>(n, -1));
	vector<pair<int, int>> cand;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	chk[sy][sx] = 0;
	int time = 0;
	bool find = false;

	while (!q.empty()) {
		int qsize = q.size();
		find = false;
		while (qsize--) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (inRange(nx, ny) && chk[ny][nx] == -1 && size >= map[ny][nx]) {
					if (map[ny][nx] > 0 && size > map[ny][nx]) {
						cand.push_back(make_pair(ny, nx));
						find = true;
					}
					chk[ny][nx] = chk[y][x] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}
		if (find) {
			sort(cand.begin(), cand.end());
			sx = cand[0].second;
			sy = cand[0].first;
			ate++;
			map[sy][sx] = 0;
			if (ate == size) {
				size++;
				ate = 0;
			}
			time += chk[sy][sx];
			while (!q.empty()) q.pop();
			q.push(make_pair(sy, sx));
			chk = vector<vector<int>>(n, vector<int>(n, -1));
			chk[sy][sx] = 0;
			cand.clear();
		}
	}
	return time;
}

void solve(vector<vector<int>>& map, vector<int>& precalc) {
	int ans = 0;
	cout << bfs(map) << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<int> precalc;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				sx = j;
				sy = i;
			}
			else if (map[i][j] > 0)
				precalc.push_back(map[i][j]);
		}
	solve(map, precalc);
	return 0;
}