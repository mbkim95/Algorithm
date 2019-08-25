#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

void bfs(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int start) {
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			int len = adj[here][i].second;
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[here] + len;
			}
		}
	}
}

void solve(vector<vector<pair<int, int>>>& adj) {
	vector<int>dist(n + 1, 0);
	int start = 1;
	bfs(adj, dist, start);
	for (int i = 1; i <= n; i++) {
		if (dist[start] < dist[i])
			start = i;
	}
	fill(dist.begin(), dist.end(), 0);
	bfs(adj, dist, start);
	for (int i = 1; i <= n; i++) {
		if (dist[start] < dist[i])
			start = i;
	}
	cout << dist[start] << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<vector<pair<int, int>>>adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	solve(adj);
	return 0;
}