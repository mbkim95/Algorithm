#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, s, e;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	dist[s] = 0;
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_cost = adj[cur][i].second + cost;

			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push(make_pair(-next_cost, next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	adj = vector<vector<pair<int, int>>>(n + 1);
	dist = vector<int>(n + 1, 987654321);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	cin >> s >> e;

	dijkstra();

	cout << dist[e] << '\n';

	return 0;
}