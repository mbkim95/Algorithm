#include <iostream>
#include <set>
using namespace std;

int map[5][5];
set<int> nums;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1};

bool inRange(int x, int y) {
	return (0 <= x && x < 5) && (0 <= y && y < 5);
}

void dfs(int x, int y, int cnt, int number) {
	if (cnt == 6) {
		nums.insert(number);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (inRange(nx, ny)) {
			dfs(nx, ny, cnt + 1, 10 * number + map[ny][nx]);
		}
	}
}

int solve() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(j, i, 1, map[i][j]);
		}
	}
	return nums.size();
}

int main() {
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++) 
			cin >> map[i][j];
	cout << solve() << '\n';
	return 0;
}