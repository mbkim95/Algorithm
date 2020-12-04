#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num, tree;

int init(int node, int start, int end) {
	if (start == end) return tree[node] = num[end];
	int mid = (start + end) / 2;
	return tree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 2e9;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, value);
	update(2 * node + 1, mid + 1, end, idx, value);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	num.resize(n + 1);
	tree.resize(4 * (n + 1));

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	init(1, 1, n);
	
	cin >> m;

	while (m--) {
		int c, i, j;
		cin >> c >> i >> j;
		if (c == 1) {
			update(1, 1, n, i, j);
			num[i] = j;
		}
		else {
			cout << query(1, 1, n, i, j) << '\n';
		}
	}
	return 0;
}