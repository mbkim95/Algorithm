#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
vector<pair<int, pair<int, int>>> edges;
int parent[200001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int kruskal() {
	sort(edges.begin(), edges.end());
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int x = edges[i].second.first;
		int y = edges[i].second.second;
		int dist = edges[i].first;
		if (find(x) == find(y))	continue;
		merge(x, y);
		sum += dist;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		edges.clear();
		for (int i = 1; i <= m; i++) parent[i] = i;

		int total_dist = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({ z, {x, y} });
			total_dist += z;
		}
		cout << total_dist - kruskal() << '\n';
	}
	return 0;
}