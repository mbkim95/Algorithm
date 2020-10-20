#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<int> adj[101001];
int dist[101001];

int bfs() {
	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == n) return dist[n];

		for (int next : adj[cur]) {
			if (!dist[next]) {
				if (next > n) dist[next] = dist[cur];
				else dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			adj[tmp].push_back(n + i);
			adj[n + i].push_back(tmp);
		}
	}
	cout << bfs() << '\n';
	return 0;
}