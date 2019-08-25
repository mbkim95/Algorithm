#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, del, ans;

void bfs(vector<vector<int>>& adj, vector<int>& edge, vector<int>& root, vector<bool>& available) {
	vector<int> visited(n, false);
	queue<int> q;
	q.push(del);
	visited[del] = true;
	available[del] = false;
	int r = root[del];
	if(r != -1)
		edge[root[del]]--;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if (!visited[next]) {
				visited[next] = true;
				available[next] = false;
				q.push(next);
			}
		}
	}
}

void solve(vector<vector<int>>& adj, vector<int>& edge, vector<int>& root) {
	vector<bool> available(n, true);
	bfs(adj, edge, root, available);
	for (int i = 0; i < n; i++) {
		if (available[i] && !edge[i])
			ans++;
	}
	cout << ans << '\n';
}

int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> edge(n, 0);
	vector<int> root(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		root[i] = tmp;
		if (tmp != -1) {
			adj[tmp].push_back(i);
			edge[tmp]++;
		}
	}
	cin >> del;
	solve(adj, edge, root);
	return 0;
}