#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n, m;
vector<ll> num, tree, lazy;

ll init(int node, int start, int end) {
	if (start == end) return tree[node] = num[end];
	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int start, int end, int left, int right, int v) {
	update_lazy(node, start, end);

	if (left > end || right < start) return;
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * v;
		if (start != end) {
			lazy[2 * node] += v;
			lazy[2 * node + 1] += v;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(2 * node, start, mid, left, right, v);
	update_range(2 * node + 1, mid + 1, end, left, right, v);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	num.resize(n + 1);
	tree.resize(4 * (n + 1));
	lazy.resize(4 * (n + 1), 0);

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	init(1, 1, n);

	cin >> m;

	while (m--) {
		int c, i, j, k;
		cin >> c;
		if (c == 1) {
			cin >> i >> j >> k;
			update_range(1, 1, n, i, j, k);
		}
		else {
			cin >> k;
			cout << query(1, 1, n, k, k) << '\n';
		}
	}
	return 0;
}