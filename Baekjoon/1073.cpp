#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> parent, height;
vector<pair<int, pair<int, int>>> edge;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
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
	sort(edge.begin(), edge.end());

	int ret = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;

		if (find(a) == find(b)) continue;
		merge(a, b);
		ret += cost;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	parent = vector<int>(n + 1);
	height = vector<int>(n + 1, 1);

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}
	cout << kruskal() << '\n';
	return 0;
}