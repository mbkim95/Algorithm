#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> num, tree;

int init(int node, int start, int end) {
	if (start == end) return tree[node] = num[end];
	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end);
}

int query(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 1;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) * query(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int v) {
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = v;
		return;
	}
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, idx, v);
		update(2 * node + 1, mid + 1, end, idx, v);
		tree[node] = tree[2 * node] * tree[2 * node + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> k) {
		num = vector<int>(n + 1);
		tree = vector<int>(4 * (n + 1));
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp > 0) num[i] = 1;
			else if (tmp == 0) num[i] = 0;
			else num[i] = -1;
		}
		init(1, 1, n);

		while (k--) {
			char c;
			int i, v;
			cin >> c >> i >> v;
			if (c == 'C') {
				if (v > 0) num[i] = 1;
				else if (v == 0) num[i] = 0;
				else num[i] = -1;
				update(1, 1, n, i, num[i]);
			}
			else {
				int result = query(1, 1, n, i, v);
				if (result > 0) cout << "+";
				else if (result == 0) cout << "0";
				else cout << "-";
			}
		}
		cout << '\n';
	}
	return 0;
}