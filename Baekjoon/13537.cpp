#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;

int n, m;
vector<int> num, tree[4 * MAX_N];

void update(int node, int start, int end, int idx, int v) {
	if (idx < start || idx > end) return;
	tree[node].push_back(v);
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, idx, v);
		update(2 * node + 1, mid + 1, end, idx, v);
	}
}

int query(int node, int start, int end, int left, int right, int v) {
	if (left > end || start > right) return 0;
	if (left <= start && end <= right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), v);

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right, v) + query(2 * node + 1, mid + 1, end, left, right, v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	num.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		update(1, 1, n, i, num[i]);
	}

	for (int i = 1; i <= 4 * MAX_N; i++)
		sort(tree[i].begin(), tree[i].end());

	cin >> m;

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		cout << query(1, 1, n, i, j, k) << '\n';
	}
	return 0;
}