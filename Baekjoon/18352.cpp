#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x;
vector<vector<int>> adj;
vector<int> dist;

void bfs() {
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (dist[now] > k) continue;

		for (int next : adj[now]) {
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k >> x;
	adj = vector<vector<int>>(n + 1);
	dist = vector<int>(n + 1, -1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	bfs();

	bool find = false;
	for (int i = 1; i <= n; i++)
		if (dist[i] == k) {
			cout << i << '\n';
			find = true;
		}

	if (!find) cout << -1 << '\n';
	return 0;
}