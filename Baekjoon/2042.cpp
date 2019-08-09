#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
vector<long long> num, tree;

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = num[start];
	else {
		int mid = (start + end) / 2;
		return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
	}
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || end < idx)
		return;
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, idx, diff);
		update(2 * node + 1, mid + 1, end, idx, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || start > right)
		return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	num = vector<long long>(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int h = (int)ceil(log2(n));
	int size = 1 << (h + 1);
	tree = vector<long long>(size);
	init(1, 0, n - 1);
	m += k;
	for (int i = 0; i < m; i++) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b -= 1;
			long long diff = c - num[b];
			num[b] = c;
			update(1, 0, n - 1, b, diff);
		}
		else
			cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
	}
	return 0;
}