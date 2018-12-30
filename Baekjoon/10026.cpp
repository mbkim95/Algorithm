#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map, chk;
const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void dfs(int x, int y, int value) {
	if (value == 1)
		chk[y][x] = 2;
	else if (value == 2)
		chk[y][x] = 3;
	else
		chk[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inRange(nextX, nextY) && map[nextY][nextX] == value && !chk[nextY][nextX]){
			dfs(nextX, nextY, value);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	chk = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == 'R')
				map[i][j] = 3;
			else if (tmp == 'G')
				map[i][j] = 2;
			else
				map[i][j] = 1;
		}
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				ans1++;
				dfs(j, i, map[i][j]);
			}
		}
	}
	chk = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 3)
				map[i][j] = 2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!chk[i][j]) {
				ans2++;
				dfs(j, i, map[i][j]);
			}
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}