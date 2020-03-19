#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSet {
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	vector<pair<int, pair<int, int>>> edge;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a, b} });
	}
	sort(edge.begin(), edge.end());
	DisjointSet set(v + 1);

	int ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int cost = edge[i].first;

		if (set.find(a) == set.find(b)) continue;
		set.merge(a, b);
		ans += cost;
	}
	cout << ans << '\n';
	return 0;
}