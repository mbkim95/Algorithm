#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int	n;
vector<vector<int>> adj;
vector<int> t, dp, inDegree;
priority_queue<pair<int, int>> q;

void solve() {
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i]) {
			q.push(make_pair(-t[i], i));
			dp[i] = t[i];
		}
	}

	while (!q.empty()) {
		pair<int, int> tmp = q.top();
		q.pop();
		int here = tmp.second;
		int time = -tmp.first; 

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			inDegree[there]--;
			if (!inDegree[there]) {
				dp[there] = max(dp[there], dp[here] + t[there]);
				q.push(make_pair(-dp[there], there));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj = vector<vector<int>>(n + 1);
	t = vector<int>(n + 1, 0);
	dp = vector<int>(n + 1, 0);
	inDegree = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		int tmp = 0;
		while (true) {
			cin >> tmp;
			if (tmp == -1)
				break;
			adj[tmp].push_back(i);
			inDegree[i]++;
		}
	}
	solve();
	return 0;
}