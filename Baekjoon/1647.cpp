#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> edges;
vector<int> root;

int find(int v) {
	if (root[v] != v)
		root[v] = find(root[v]);
	return root[v];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b)
		root[b] = a;
	else
		root[a] = b;
}

int kruskal() {
	int last = 0;
	int sum = 0;

	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int c = edges[i].first;
		if (find(a) == find(b)) continue;
		merge(a, b);
		sum += c;
		last = c;
	}
	return sum - last;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	root = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
		root[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}
	sort(edges.begin(), edges.end());
	cout << kruskal() << '\n';
	return 0;
}