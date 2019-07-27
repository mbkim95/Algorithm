#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> map;
queue<pair<int, int>> Q;
vector<pair<int, int>> cand;
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };

bool inRange(int x, int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}

bool isFinished(vector<vector<int>>& map) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!map[i][j])
				return false;
	return true;
}

int getCount(vector<vector<int>>& map) {
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				ret++;
		}
	}
	return ret;
}


int bfs() {
	vector<vector<int>> m = map;
	queue<pair<int, int>> q = Q;

	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();

		if (isFinished(m))
			break;

		for (int i = 0; i < 4; i++) {
			int nextX = tmp.first + dx[i];
			int nextY = tmp.second + dy[i];

			if (inRange(nextX, nextY) && !m[nextY][nextX]) {
				q.push(make_pair(nextX, nextY));
				m[nextY][nextX] = 2;
			}
		}
	}
	return getCount(m);
}

void solve() {
	int ans = 0;
	pair<int, int> w1, w2, w3;
	for (int i = 0; i < cand.size()-2; i++) {
		w1 = cand[i];
		map[w1.second][w1.first] = 1;
		for (int j = i+1; j < cand.size()-1; j++) {
			w2 = cand[j];
			map[w2.second][w2.first] = 1;
			for (int k = j+1; k < cand.size(); k++) {
				w3 = cand[k];
				map[w3.second][w3.first] = 1;
				ans = max(ans, bfs());
				map[w3.second][w3.first] = 0;
			}
			map[w2.second][w2.first] = 0;
		}
		map[w1.second][w1.first] = 0;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				cand.push_back(make_pair(j, i));
			if (map[i][j] == 2)
				Q.push(make_pair(j, i));
		}
	}
	solve();
	return 0;
}