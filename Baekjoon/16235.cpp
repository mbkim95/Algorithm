#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, ans;
vector<vector<int>> a;
vector<vector<int>> ground;
vector<vector<vector<int>>> tree;
vector<pair<pair<int, int>, int>> dead;
vector<pair<int, int>> old;

bool inRange(int x, int y) {
	return (1 <= x && x <= n) && (1 <= y && y <= n);
}

void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cnt = tree[i][j].size();
			queue<int> q;
			if(cnt > 1)
				sort(tree[i][j].begin(), tree[i][j].end());
			for (int l = 0; l < cnt; l++) {
				int feed = tree[i][j][l];
				if (ground[i][j] < feed) {
					dead.push_back(make_pair(make_pair(j, i), feed/2));
					ans--;
				}
				else {
					ground[i][j] -= feed;
					tree[i][j][l]++;
					q.push(tree[i][j][l]);
					if (tree[i][j][l] % 5 == 0)
						old.push_back(make_pair(j, i));
				}
			}
			tree[i][j].clear();
			while (!q.empty()) {
				int tmp = q.front();
				q.pop();
				tree[i][j].push_back(tmp);
			}
		}
	}
}

void summer() {
	for (int i = 0; i < dead.size(); i++) {
		int x = dead[i].first.first;
		int y = dead[i].first.second;
		int feed = dead[i].second;
		ground[y][x] += feed;
	}
	dead.clear();
}

void fall() {
	const int dx[] = { -1, 0, 1, -1, 1, -1 ,0, 1 }, dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	for (int i = 0; i < old.size(); i++) {
		int x = old[i].first;
		int y = old[i].second;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inRange(nx, ny)) {
				tree[ny][nx].push_back(1);
				ans++;
			}
		}
	}
	old.clear();
}

void winter() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			ground[i][j] += a[i][j];
}

void solve() {
	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	ans = m;
	a = vector<vector<int>>(n + 1, vector<int>(n + 1));
	ground = vector<vector<int>>(n + 1, vector<int>(n + 1, 5));
	tree = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	solve();
	return 0;
}