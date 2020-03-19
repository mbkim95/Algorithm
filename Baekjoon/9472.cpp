#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> parent, height;
vector<pair<int, pair<int, int>>> edge;

int find(int node) {
	if (node == parent[node]) return node;
	return parent[node] = find(parent[node]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return;

	if (height[u] > height[v]) swap(u, v);
	parent[u] = v;
	if (height[u] == height[v]) height[v]++;
}

int kruskal() {
	int ret = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;

		if (find(a) == find(b)) continue;

		merge(a, b);
		ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		parent = vector<int>(n + 1);
		height = vector<int>(n + 1, 1);
		edge.clear();
		for (int i = 0; i <= n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			edge.push_back({ 1, {a, b} });
		}
		cout << kruskal() << '\n';
	}
	return 0;
}