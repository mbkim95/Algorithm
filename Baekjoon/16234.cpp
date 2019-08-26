#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n, l, r, sum;
vector<vector<int>> map;
vector<vector<int>> open;
vector<pair<int, int>> list;
bool fin = true;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < n);
}

void dfs(int x, int y, int k) {
	open[y][x] = k;
	list.push_back(make_pair(x, y));
	sum += map[y][x];

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inRange(nx, ny) && !open[ny][nx]) {
			int diff = abs(map[ny][nx] - map[y][x]);
			if (l <= diff && diff <= r) {
				fin = false;
				dfs(nx, ny, k);
			}
		}
	}
}

void movePeople() {
	sum /= list.size();
	for (int i = 0; i < list.size(); i++)
		map[list[i].second][list[i].first] = sum;
}

void solve() {
	int ans = 0;
	int k = 1;
	while (true) {
		fin = true;
		open = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!open[i][j]) {
					sum = 0;
					list.clear();
					dfs(j, i, k++);
					movePeople();
				}
			}
		}
		if (fin)
			break;
		ans++;
		k = 1;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> r;
	map = vector<vector<int>>(n, vector<int>(n));
	open = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	solve();
}