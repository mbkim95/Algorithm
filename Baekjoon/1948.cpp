#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, s, e;
vector<bool> visited;
vector<int> in_degree, dp;
vector<vector<pair<int,int>>> adj, rev_adj;

int bfs() {
	queue<int> q;
	q.push(e);

	int ret = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < rev_adj[cur].size(); i++) {
			int next = rev_adj[cur][i].first;
			int t = rev_adj[cur][i].second;
			if (dp[cur] - t == dp[next]) {
				ret++;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}
	return ret;
}

int topological_sort() {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int t = adj[cur][i].second;
			in_degree[next]--;
			dp[next] = max(dp[next], dp[cur] + t);		
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}
	return dp[e];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;
	dp = vector<int>(n + 1, 0);
	in_degree = vector<int>(n + 1, 0);
	adj = vector<vector<pair<int, int>>>(n + 1);
	rev_adj = vector<vector<pair<int, int>>>(n + 1);
	visited = vector<bool>(n + 1, false);
	
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		rev_adj[b].push_back({ a, t });
		in_degree[b]++;
	}
	cin >> s >> e;
	cout << topological_sort() << '\n' << bfs() << '\n';
	return 0;
}