#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet {
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
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

	int n, m;
	cin >> n >> m;
	DisjointSet set = DisjointSet(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)
			set.merge(b, c);
		else if (a == 1) {
			int p1 = set.find(b);
			int p2 = set.find(c);
			if (p1 == p2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}