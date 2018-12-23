#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
vector<vector<int>> mat;
vector<int> ans;
const int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void dfs(int x, int y) {
	mat[y][x] = 0;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inRange(nextX, nextY) && mat[nextY][nextX]) {
			dfs(nextX, nextY);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j]) {
				dfs(j, i);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	scanf("%d", &n);
	mat = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}
	solve();
	return 0;
}