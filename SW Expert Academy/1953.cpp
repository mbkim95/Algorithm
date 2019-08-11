#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans;
int n, m, r, c, l;
vector<vector<int>> map;
vector<vector<bool>> cand;
queue<pair<int, int>> q;
const int dx[] = { 0, 0, -1, 1 }, dy[] = { -1, 1, 0, 0 };

void reset() {
	while (!q.empty())
		q.pop();
}

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

void getAnswer() {
	ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (cand[i][j])
				ans++;
	}
}

bool checkTile(int tile, int dir, int next) {
	if (tile == 1) {
		if (dir == 0) {
			if (next == 1 || next == 2 || next == 5 || next == 6)
				return true;
		}
		else if (dir == 1) {
			if (next == 1 || next == 2 || next == 4 || next == 7)
				return true;
		}
		else if (dir == 2) {
			if (next == 1 || next == 3 || next == 4 || next == 5)
				return true;
		}
		else {
			if (next == 1 || next == 3 || next == 6 || next == 7)
				return true;
		}		
	}
	else if (tile == 2) {
		if (dir == 0) {
			if (next == 1 || next == 2 || next == 5 || next == 6)
				return true;
		}
		else if (dir == 1) {
			if (next == 1 || next == 2 || next == 4 || next == 7)
				return true;
		}
	}
	else if (tile == 3) {
		if (dir == 2) {
			if (next == 1 || next == 3 || next == 4 || next == 5)
				return true;
		}
		else if (dir == 3)
			if (next == 1 || next == 3 || next == 6 || next == 7)
				return true;
	}
	else if (tile == 4) {
		if (dir == 0) {
			if (next == 1 || next == 2 || next == 5 || next == 6)
				return true;
		}
		else if (dir == 3) {
			if (next == 1 || next == 3 || next == 6 || next == 7)
				return true;
		}
	}
	else if (tile == 5) {
		if (dir == 1) {
			if (next == 1 || next == 2 || next == 4 || next == 7)
				return true;
		}
		else if (dir == 3) {
			if (next == 1 || next == 3 || next == 6 || next == 7)
				return true;
		}
	}
	else if (tile == 6) {
		if (dir == 2) {
			if (next == 1 || next == 3 || next == 4 || next == 5)
				return true;
		}
		else if (dir == 1) {
			if (next == 1 || next == 2 || next == 4 || next == 7)
				return true;
		}
	}
	else if (tile == 7) {
		if (dir == 0) {
			if (next == 1 || next == 2 || next == 5 || next == 6)
				return true;
		}
		else if (dir == 2) {
			if (next == 1 || next == 3 || next == 4 || next == 5)
				return true;
		}
	}
	return false;
}

void bfs() {
	reset();
	q.push(make_pair(c, r));
	int time = 0;
	int x = r, y = c;
	while (!q.empty()) {
		int size = q.size();
		if (time == l) {
			getAnswer();
			return;
		}
		while (size--) {
			pair<int, int> tmp = q.front();
			q.pop();
			cand[tmp.second][tmp.first] = true;
			int tile = map[tmp.second][tmp.first];

			if (tile == 1) {// 상하좌우
				for (int i = 0; i < 4; i++) {
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 2) {	// 위아래
				for (int i = 0; i < 2; i++) {
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 3) {	// 좌우
				for (int i = 2; i < 4; i++) {
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 4) {	// 오른쪽 위
				for (int i = 0; i < 4; i++) {
					if (i == 1 || i == 2)
						continue;
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 5) {	// 오른쪽 아래
				for (int i = 0; i < 4; i++) {
					if (i == 0 || i == 2)
						continue;
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 6) {	// 왼쪽 아래
				for (int i = 0; i < 4; i++) {
					if (i == 0 || i == 3)
						continue;
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
			else if (tile == 7) {	// 왼쪽 위
				for (int i = 0; i < 4; i++) {
					if (i == 1 || i == 3)
						continue;
					int nextX = tmp.first + dx[i];
					int nextY = tmp.second + dy[i];
					if (inRange(nextX, nextY)) {
						int next = map[nextY][nextX];
						if (checkTile(tile, i, next) && !cand[nextY][nextX])
							q.push(make_pair(nextX, nextY));
					}
				}
			}
		}
		time++;
	}
	getAnswer();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int C = 1; C <= t; C++) {
		cin >> n >> m >> r >> c >> l;
		map = vector<vector<int>>(n, vector<int>(m));
		cand = vector<vector<bool>>(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> map[i][j];
		bfs();
		cout << '#' << C << ' ' << ans << '\n';
	}
}