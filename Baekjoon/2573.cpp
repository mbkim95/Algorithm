#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt;
vector<vector<int>> map, visited;
vector<pair<int, int>> ice;
vector<pair<int, pair<int, int>>> melt;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

void dfs(int x, int y) {
	visited[y][x] = 1;
	cnt++;

	int melt_cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (inRange(nx, ny)) {
			if (map[ny][nx] == 0)
				melt_cnt++;

			if (map[ny][nx] != 0 && !visited[ny][nx]) {
				dfs(nx, ny);
			}
		}
	}

	melt.push_back(make_pair(melt_cnt, make_pair(x, y)));
}

int solve() {
	int ans = 0;
	bool find = false;

	while (!ice.empty()) {
		find = false;
		visited = vector<vector<int>>(n, vector<int>(m, 0));
		cnt = 0;

		int x = ice[0].first;
		int y = ice[0].second;
		if (map[y][x] != 0 && !visited[y][x]) {
			find = true;
			dfs(x, y);
		}

		if (cnt != ice.size()) 
			break;

		ice.clear();
		int all_cnt = 0;
		for (int i = 0; i < melt.size(); i++) {
			int tx = melt[i].second.first;
			int ty = melt[i].second.second;
			int melting = melt[i].first;

			if (map[ty][tx] - melting > 0) {
				map[ty][tx] -= melting;
				ice.push_back(make_pair(tx, ty));
			}
			else {
				map[ty][tx] = 0;
				all_cnt++;
			}
		}
		if (all_cnt == melt.size()) {
			find = false;
			break;
		}
		melt.clear();
		ans++;
	}
	return find ? ans : 0;
}

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));
	visited = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] > 0)
				ice.push_back(make_pair(j, i));
		}
	}

	cout << solve() << '\n';
	return 0;
}