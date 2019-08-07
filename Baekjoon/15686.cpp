#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, ans;
vector<vector<int>> map;
vector<pair<int, int>> home, chicken, cand;

void dfs(int cnt, int idx) {
	if (idx == chicken.size())
		return;

	if (cnt == m) {
		int tmp = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = 987654321;
			for (int j = 0; j < cand.size(); j++) {
				dist = min(dist, abs(home[i].first - cand[j].first) + abs(home[i].second - cand[j].second));
			}
			tmp += dist;
		}
		ans = min(ans, tmp);
		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++) {
		cand.push_back(chicken[i]);
		dfs(cnt + 1, i);
		cand.pop_back();
	}
}

void solve() {
	ans = 987654321;
	for (int i = 0; i < chicken.size(); i++) {
		cand.push_back(chicken[i]);
		dfs(1, i);
		cand.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				home.push_back(make_pair(j, i));
			if (map[i][j] == 2)
				chicken.push_back(make_pair(j, i));
		}
	}
	solve();
	cout << ans << '\n';
	return 0;
}