#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> edge;
vector<int> tree;

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int v) {
	if (idx < start || idx > end) return;
	tree[node] += v;
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, idx, v);
		update(2 * node + 1, mid + 1, end, idx, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	tree.resize(4 * (n + 1), 0);

	while (m--) {
		int i, j;
		cin >> i >> j;
		edge.push_back({ i, j });
	}

	sort(edge.begin(), edge.end());

	long long ans = 0;	
	for (auto it : edge) {
		ans += sum(1, 1, n, it.second + 1, n);
		update(1, 1, n, it.second, 1);
	}
	cout << ans << '\n';
	return 0;
}
