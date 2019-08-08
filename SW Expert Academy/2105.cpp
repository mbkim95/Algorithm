#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<bool> dessert;
vector<vector<int>> cafe;
const int dx[] = { -1, 1, 1, -1 }, dy[] = { 1, 1, -1, -1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int countDessert() {
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		if (dessert[i])
			cnt++;
	}
	return cnt;
}

void dfs(pair<int, int> start, int x, int y, int cnt, int dir) {
	if (cnt > 3 && dir == 3 && start.first == x && start.second == y){
		ans = max(ans, countDessert());
		return;
	}

	for (int i = dir; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (inRange(nx, ny) && !dessert[cafe[ny][nx]]) {
			dessert[cafe[ny][nx]] = true;
			dfs(start, nx, ny, cnt + 1, i);
			dessert[cafe[ny][nx]] = false;
		}

		if (cnt > 3 && i == 3 && start.first == nx && start.second == ny && dessert[cafe[ny][nx]]) 
			dfs(start, nx, ny, cnt, i);
	}

}

void dfsAll() {
	for (int i = 0; i < n - 2; i++)
		for (int j = 1; j < n - 1; j++) {
			dessert[cafe[i][j]] = true;
			dfs(make_pair(j, i), j, i, 1, 0);
			dessert[cafe[i][j]] = false;
		}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int c = 1; c <= t; c++) {
		scanf("%d", &n);
		cafe = vector<vector<int>>(n, vector<int>(n));
		dessert = vector<bool>(101, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &cafe[i][j]);
			}
		}
		ans = 0;
		dfsAll();
		ans = ans == 0 ? -1 : ans;
		printf("#%d %d\n", c, ans);
	}
	return 0;
}