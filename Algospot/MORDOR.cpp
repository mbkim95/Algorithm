#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
vector<int> max_tree, min_tree, h;

int init(vector<int>& tree, int node, int start, int end, int op) {
	if (start == end) return tree[node] = op * h[end];
	int mid = (start + end) / 2;
	return tree[node] = min(init(tree, 2 * node, start, mid, op), init(tree, 2 * node + 1, mid + 1, end, op));
}

int query(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 987654321;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(tree, 2 * node, start, mid, left, right), query(tree, 2 * node + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	while (c--) {
		cin >> n >> q;
		h = vector<int>(n);
		max_tree = vector<int>(4 * n);
		min_tree = vector<int>(4 * n);
		for (int i = 0; i < n; i++)
			cin >> h[i];

		init(max_tree, 1, 0, n - 1, -1);
		init(min_tree, 1, 0, n - 1, 1);

		for (int i = 0; i < q; i++) {
			int a, b;
			cin >> a >> b;
			int max_value = -query(max_tree, 1, 0, n - 1, a, b);
			int min_value = query(min_tree, 1, 0, n - 1, a, b);
			cout << max_value - min_value << '\n';
		}
	}
	return 0;
}