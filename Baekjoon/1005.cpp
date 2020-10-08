#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k, w;
vector<int> d, in_degree, dp;
vector<vector<int>> adj;

int topological_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			dp[i] = d[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == w) break;

		for (int next : adj[cur]) {
			in_degree[next]--;
			dp[next] = max(dp[next], dp[cur] + d[next]);
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}
	return dp[w];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		d = vector<int>(n + 1);
		in_degree = vector<int>(n + 1, 0);
		dp = vector<int>(n + 1, 0);
		adj = vector<vector<int>>(n + 1);

		for (int i = 1; i <= n; i++)
			cin >> d[i];

		while (k--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			in_degree[b]++;
		}
		cin >> w;
		cout << topological_sort() << '\n';
	}
	return 0;
}