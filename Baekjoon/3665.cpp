#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<bool>> adj;
vector<int> ranking;
vector<int> in_degree;

void topological_sort() {
	vector<int> result;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)
			q.push(i);
	}

	bool is_cycle = false;
	bool is_certain = true;

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			is_cycle = true;
			break;
		}
		else if (q.size() >= 2) {
			is_certain = false;
			break;
		}
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int j = 1; j <= n; j++) {
			if (adj[cur][j]) {
				in_degree[j]--;
				if (in_degree[j] == 0)
					q.push(j);
			}
		}
	}
	if (is_cycle)
		cout << "IMPOSSIBLE\n";
	else if (!is_certain)
		cout << "?\n";
	else {
		for (int i = 0; i < n; i++)
			cout << result[i] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ranking = vector<int>(n + 1);
		in_degree = vector<int>(n + 1, 0);
		adj = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
		for (int i = 1; i <= n; i++)
			cin >> ranking[i];

		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) {
				adj[ranking[i]][ranking[j]] = true;
				in_degree[ranking[j]]++;
			}

		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (adj[a][b]) {
				adj[a][b] = false;
				adj[b][a] = true;
				in_degree[a]++;
				in_degree[b]--;
			}
			else {
				adj[a][b] = true;
				adj[b][a] = false;
				in_degree[a]--;
				in_degree[b]++;
			}
		}
		topological_sort();
	}
	return 0;
}