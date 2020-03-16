#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pr;
int v, e, k;
vector<vector<pr>> adj;
vector<int> dist;

void dijkstra() {
	priority_queue<pr, vector<pr>, greater<pr>> pq;
	pq.push(make_pair(0, k));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cost > dist[cur]) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int next_cost = adj[cur][i].second;

			if (dist[next] > dist[cur] + next_cost) {
				dist[next] = dist[cur] + next_cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	cin >> k;
	adj = vector<vector<pr>>(v + 1);
	dist = vector<int>(v + 1, 987654321);
	dist[k] = 0;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}

	dijkstra();
	
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 987654321)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
	return 0;
}