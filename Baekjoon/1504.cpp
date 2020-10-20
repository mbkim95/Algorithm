#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1e9;
int n, e, v1, v2;
vector<pair<int, int>> adj[801];
bool visited[801];
int dist[801];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur_dist > dist[cur]) continue;

		for (auto i : adj[cur]) {
			int next = i.first;
			int cost = i.second + cur_dist;
			if (dist[next] > cost) {
				dist[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

long long solve() {
	long long ans1 = 0;
	long long ans2 = 0;	
	for (int i = 1; i <= n; i++) dist[i] = MAX;
	dijkstra(1);
	ans1 += dist[v1];
	ans2 += dist[v2];

	for (int i = 1; i <= n; i++) dist[i] = MAX;
	dijkstra(v1);
	ans1 += dist[v2];
	ans2 += dist[n];

	for (int i = 1; i <= n; i++) dist[i] = MAX;
	dijkstra(v2);
	ans1 += dist[n];
	ans2 += dist[v1];

	return min(ans1, ans2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	long long ans = solve();
	if (ans >= MAX) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}