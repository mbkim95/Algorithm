#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<int> movie, tree, pos;

int init(int node, int start, int end) {
	if (start == end) return tree[node] = movie[end];
	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

int sum(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 0;
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

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		int max_pos = n + 1;
		pos = vector<int>(n + 1);
		movie = vector<int>(n + m + 1);
		tree = vector<int>(4 * (n + m + 1), 0);

		for (int i = 1; i <= n; i++) {
			movie[i] = 1;
			pos[i] = n + 1 - i;
		}

		init(1, 1, m + n);

		for (int i = 0; i < m; i++) {
			int pick;
			cin >> pick;
			cout << sum(1, 1, m + n, pos[pick] + 1, m + n) << ' ';
			update(1, 1, m + n, pos[pick], -1);
			pos[pick] = max_pos++;
			update(1, 1, m + n, pos[pick], 1);
		}
		cout << '\n';
	}
	return 0;
}