#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
vector<long long> num, tree;

long long init(int node, int start, int end) {
	if (start == end) return tree[node] = num[end];
	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, idx, diff);
		update(2 * node + 1, mid + 1, end, idx, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	num.resize(n + 1);
	tree.resize(4 * (n + 1));

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	init(1, 1, n);
	for (int i = 0; i < q; i++) {
		int x, y, a;
		long long b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum(1, 1, n, x, y) << '\n';
		update(1, 1, n, a, b - num[a]);
		num[a] = b;
	}
	return 0;
}