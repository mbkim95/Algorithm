#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int parent[101];
vector<pair<double, double>> stars;
vector<pair<double, pair<int, int>>> edges;

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

double kruskal() {
	sort(edges.begin(), edges.end());
	double sum = 0;
	
	for (int i = 0; i < edges.size(); i++) {
		double dist = edges[i].first;
		int star1 = edges[i].second.first;
		int star2 = edges[i].second.second;
		if (find(star1) == find(star2)) continue;
		sum += dist;
		merge(star1, star2);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back({ x, y });
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double x_diff = stars[i].first - stars[j].first;
			double y_diff = stars[i].second - stars[j].second;
			double dist = sqrt(x_diff * x_diff + y_diff * y_diff);
			edges.push_back({ dist, {i + 1, j + 1} });
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << kruskal() << '\n';
	return 0;
}