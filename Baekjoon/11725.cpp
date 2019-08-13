#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> visited;
vector<int>ans;
vector<vector<int>>adj;

void dfs(int here, int parent) {
	visited[here] = true;
	ans[here] = parent;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there, here);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	ans = vector<int>(n + 1);
	visited = vector<bool>(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp1].push_back(tmp2);
		adj[tmp2].push_back(tmp1);
	}
	dfs(1, 1);
	for (int i = 2; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}