#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char map[12][7];
bool visited[12][6];
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
vector<pair<int, int>> temp;
vector<pair<int, int>> boom;
int cnt;

bool inRange(int x, int y) {
	return (0 <= x && x < 6) && (0 <= y && y < 12);
}

void down() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 1; i--) {
			if (map[i][j] == '.') {
				int temp = i - 1;
				bool find = false;
				while (temp >= 0) {
					if (map[temp][j] != '.') {
						find = true;
						break;
					}
					temp--;
				}
				if (find) {
					map[i][j] = map[temp][j];
					map[temp][j] = '.';
				}
			}
		}
	}
}

void dfs(int x, int y, char current) {
	temp.push_back(make_pair(x, y));
	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (inRange(nx, ny) && map[ny][nx] == current && !visited[ny][nx]) {
			dfs(nx, ny, current);
		}
	}
}

int solve() {
	bool find = true;
	int ans = 0;

	while (find) {
		find = false;
		memset(visited, false, sizeof(visited));
		down();

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && !visited[i][j]) {
					cnt = 0;
					dfs(j, i, map[i][j]);

					if (cnt >= 4) {
						for (int i = 0; i < temp.size(); i++) {
							boom.push_back(temp[i]);
							find = true;
						}
					}
				}
				temp.clear();
			}
		}

		if (find) {
			for (int i = 0; i < boom.size(); i++) {
				pair<int, int> cur = boom[i];
				map[cur.second][cur.first] = '.';
			}
			ans++;
			boom.clear();
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	cout << solve() << '\n';
	return 0;
}
