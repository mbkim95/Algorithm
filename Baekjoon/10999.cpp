#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<long long> num, tree, lazy;

long long init(int node, int start, int end) {
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

void update_range(int node, int start, int end, int left, int right, long long diff) {
	update_lazy(node, start, end);

	if (left > end || start > right) return;
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[2 * node] += diff;
			lazy[2 * node + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(2 * node, start, mid, left, right, diff);
	update_range(2 * node + 1, mid + 1, end, left, right, diff);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

long long sum(int node, int start, int end, int left, int  right) {
	update_lazy(node, start, end);

	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	num.resize(n);
	tree.resize(4 * n);
	lazy.resize(4 * n, 0);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		long long d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update_range(1, 0, n - 1, b - 1, c - 1, d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}