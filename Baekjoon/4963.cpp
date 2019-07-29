#include <iostream>
#include <vector>
using namespace std;

int w, h;
vector<vector<int>> map, visited;
const int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < w) && (0 <= y && y < h);
}

void dfs(int x, int y) {
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx, ny) && !visited[ny][nx] && map[ny][nx] == 1) {
			dfs(nx, ny);
		}
	}
}

int solve() {
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visited[i][j] && map[i][j]) {
				dfs(j, i);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	w = 1, h = 1;

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		map = vector<vector<int>>(h, vector<int>(w, 0));
		visited = vector<vector<int>>(h, vector<int>(w, 0));
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++)
				cin >> map[i][j];				
		cout << solve() << '\n';
	}
	return 0;
}