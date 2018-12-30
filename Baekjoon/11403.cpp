#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> adj, ans;
vector<int> visited;

void dfs(int idx) {
	for (int i = 1; i <= n; i++) {
		if (adj[idx][i] && !visited[i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	ans = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> adj[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		visited = vector<int>(n + 1, 0);
		dfs(i);
		for (int j = 1; j <= n; j++) {
			if (visited[j])
				ans[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}