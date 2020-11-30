#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<long long> num, tree;

long long init(int node, int start, int end) {
	if (start == end) return tree[node] = num[end];
	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	num.resize(n + 1, 0);
	tree.resize(4 * (n + 1));

	init(1, 1, n);
	while(m--){
		int c, i, j;
		cin >> c >> i >> j;
		
		if (c == 0) {
			if (i > j) swap(i, j);
			cout << sum(1, 1, n, i, j) << '\n';
		}
		else {
			update(1, 1, n, i, j - num[i]);
			num[i] = j;
		}
	}
	return 0;
}