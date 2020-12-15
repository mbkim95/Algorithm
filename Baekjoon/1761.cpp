#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 40001;
const int BIT = 17;

int n, m;
int depth[MAX_N], dist[MAX_N];
int parent[MAX_N][BIT];
vector<pair<int, int>> adj[40001];

void make_tree(int idx) {
	for (auto it : adj[idx]) {
		int next = it.first;
		int cost = it.second;
		if (dist[next] == -1) {
			depth[next] = depth[idx] + 1;
			dist[next] = dist[idx] + cost;
			parent[next][0] = idx;
			make_tree(next);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	int diff = depth[a] - depth[b];

	for (int i = 0; i < depth[a] - depth[b]; i++) {
		if (diff & 1) a = parent[a][i];
		diff >>= 1;
	}
	if (a == b) return a;
	for (int i = BIT - 1; i >= 0; i--)
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	return parent[a][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	memset(dist, -1, sizeof(dist));
	dist[1] = 0;
	make_tree(1);

	for (int j = 1; j < BIT; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];

	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		int c = lca(a, b);
		cout << dist[a] + dist[b] - 2 * dist[c] << '\n';
	}
	return 0;
}