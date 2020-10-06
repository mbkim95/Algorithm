#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct planet {
	int idx, x, y, z;
};

int n;
vector<planet> p;
vector<pair<int, pair<int, int>>> edges;
vector<int> root;

bool comp_x(planet& p1, planet& p2) {
	return p1.x < p2.x;
}

bool comp_y(planet& p1, planet& p2) {
	return p1.y < p2.y;
}

bool comp_z(planet& p1, planet& p2) {
	return p1.z < p2.z;
}

int find(int a) {
	if (root[a] == a) return a;
	return root[a] = find(root[a]);
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
	int sum = 0;
	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int c = edges[i].first;
		if (find(a) == find(b)) continue;
		merge(a, b);
		sum += c;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	p = vector<planet>(n);
	root = vector<int>(n);

	for (int i = 0; i < n; i++) root[i] = i;

	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z;
		p[i].idx = i;
	}

	sort(p.begin(), p.end(), comp_x);
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ p[i + 1].x - p[i].x, {p[i].idx, p[i + 1].idx} });

	sort(p.begin(), p.end(), comp_y);
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ p[i + 1].y - p[i].y, {p[i].idx, p[i + 1].idx} });

	sort(p.begin(), p.end(), comp_z);
	for (int i = 0; i < n - 1; i++)
		edges.push_back({ p[i + 1].z - p[i].z, {p[i].idx, p[i + 1].idx} });

	sort(edges.begin(), edges.end());
	cout << kruskal() << '\n';
	return 0;
}