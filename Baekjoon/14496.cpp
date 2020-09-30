#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
int a, b, n, m;
vector<vector<int>> adj;
vector<int> dist;
vector<bool> visited;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	visited[start] = true;

	while (!pq.empty()) {
		int now_dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (now_dist > dist[now]) continue;

		for (int i : adj[now]) {
			int cost = now_dist + 1;
			if (cost < dist[i]) {
				dist[i] = cost;
				pq.push({ cost, i });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	dist = vector<int>(n + 1, INF);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		adj[c1].push_back(c2);
		adj[c2].push_back(c1);
	}

	dijkstra(a);
	if (dist[b] == INF) cout << "-1\n";
	else cout << dist[b] << '\n';
	return 0;
}