#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, h;
vector<vector<vector<int>>> map;
queue<pair<int, pair<int, int>>>q;
const int dx[] = { -1, 0, 1, 0, 0, 0 }, dy[] = { 0, -1, 0, 1, 0, 0 }, dz[] = { 0, 0, 0, 0, -1, 1 };

bool inRange(int x, int y, int z) {
	return (0 <= x && x < m) && (0 <= y && y < n) && (0 <= z && z < h);
}

bool isFinished() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

int bfs() {
	int time = 0;

	while (true) {
		if (isFinished()) {
			return time;
		}
		else {
			if (q.empty()) {
				return -1;
			}
		}
		int size = q.size();
		while (size--) {

			pair<int, pair<int, int>> tmp = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {
				int x = tmp.first + dx[i];
				int y = tmp.second.first + dy[i];
				int z = tmp.second.second + dz[i];

				if (inRange(x, y, z) && map[z][y][x] == 0) {
					q.push(make_pair(x, make_pair(y, z)));
					map[z][y][x] = 1;
				}
			}
		}
		time++;
	}
	return time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	map = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int >(m, 0)));

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_pair(k, make_pair(j, i)));
				}
			}
		}
	}
	cout << bfs() << '\n';
	return 0;
}