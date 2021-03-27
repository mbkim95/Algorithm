#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
vector<vector<int>> adj;
bool visited[1001];

void dfs(int cur) {
	cout << cur << ' ';
	visited[cur] = true;
	for (int next : adj[cur]) {
		if (!visited[next])
			dfs(next);
	}
}

void bfs() {
	queue<int> q;
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (int next : adj[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;
	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	dfs(v);
	cout << '\n';
	for (int i = 1; i <= n; i++) visited[i] = false;
	bfs();
	cout << '\n';
	return 0;
}
