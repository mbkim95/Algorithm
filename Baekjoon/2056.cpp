#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dp;
vector<int> in_degree;
vector<int> t;

int topological_sort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			q.push(i);
			dp[i] = t[i];
		}
	}
	int total_time = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			in_degree[next]--;
			dp[next] = max(dp[next], dp[cur] + t[next]);
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		total_time = max(total_time, dp[i]);
	return total_time;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	adj = vector<vector<int>>(n + 1);
	dp = vector<int>(n + 1, 0);
	in_degree = vector<int>(n + 1, 0);
	t = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> t[i] >> tmp;
		while (tmp--) {
			int c;
			cin >> c;
			adj[c].push_back(i);
			in_degree[i]++;
		}
	}
	cout << topological_sort() << '\n';
	return 0;
}