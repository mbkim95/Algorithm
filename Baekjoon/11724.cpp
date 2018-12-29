#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int idx) {
	visited[idx] = 1;

	for (int i = 0; i < adj[idx].size(); i++) {
		if (!visited[adj[idx][i]])
			dfs(adj[idx][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1, vector<int>());
	visited = vector<bool>(n + 1, false);
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}