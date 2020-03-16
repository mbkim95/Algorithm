#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x;
vector<vector<pair<int, int>>> r1, r2;
vector<int> ans, dist;

void dijkstra(int idx, vector<vector<pair<int, int>>>& road) {
	priority_queue<pair<int, int>> pq;
	dist = vector<int>(n + 1, 987654321);
	dist[idx] = 0;
	pq.push({ 0, idx });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[cur] < cost) continue;

		for (int i = 0; i < road[cur].size(); i++) {
			int next = road[cur][i].first;
			int next_cost = road[cur][i].second + cost;
			if (dist[next] > next_cost) {
				dist[next] = next_cost;
				pq.push({ -next_cost, next });
			}
		}
	}
}

int solve() {
	ans = vector<int>(n + 1, 0);
	
	dijkstra(x, r2);
	for (int i = 1; i <= n; i++) {
		ans[i] += dist[i];
	}
	dijkstra(x, r1);
	for (int i = 1; i <= n; i++) {
		ans[i] += dist[i];
	}
	int ret = 0;

	for (int i = 1; i <= n; i++) {
		ret = max(ret, ans[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;
	r1 = vector<vector<pair<int, int>>>(m + 1);
	r2 = vector<vector<pair<int, int>>>(m + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		r1[a].push_back({ b, c });
		r2[b].push_back({ a, c });
	}
	cout << solve() << '\n';
	return 0;
}