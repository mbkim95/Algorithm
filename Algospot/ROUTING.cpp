#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int n, m;
vector<vector<pair<int, double>>> adj;
vector<double> dist;

void dijkstra() {
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 1.0, 0 });
	dist[0] = 1.0;

	while (!pq.empty()) {
		int idx = pq.top().second;
		double cost = pq.top().first;
		pq.pop();

		if (dist[idx] < cost) continue;

		for (int i = 0; i < adj[idx].size(); i++) {
			int next = adj[idx][i].first;
			double next_cost = adj[idx][i].second * cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ next_cost, next });
			}
		}
	}
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &n, &m);
		dist = vector<double>(n, numeric_limits<double>::max());
		adj = vector<vector<pair<int, double>>>(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			double c;
			scanf("%d %d %lf", &a, &b, &c);
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
		dijkstra();
		printf("%.10f\n", dist[n - 1]);
	}
	return 0;
}