#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define DIV 1000000007

int n, m, k;
vector<long long> num, tree;

long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = num[start];
	}
	else {
		int  mid = (start + end) / 2;
		return tree[node] = ((init(2 * node, start, mid) % DIV) * (init(2 * node + 1, mid + 1, end) % DIV)) % DIV;
	}
}

long long update(int node, int start, int end, int idx, long long value) {
	if (idx < start || end < idx)
		return tree[node];
	if (start == end) 
		return tree[node] = value;

	int mid = (start + end) / 2;
	return tree[node] = (update(2 * node, start, mid, idx, value) * update(2 * node + 1, mid + 1, end, idx, value)) % DIV;
}

long long mul(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return (mul(2 * node, start, mid, left, right) * mul(2 * node + 1, mid + 1, end, left, right)) % DIV;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	num = vector<long long>(n);
	for (int i = 0; i < n; i++){
		cin >> num[i];
	}
	int h = (int)ceil(log2(n));
	int size = 1 << (h + 1);
	tree = vector<long long>(size);
	m += k;
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			update(1, 0, n - 1, b, c);
		}
		else {
			cout << mul(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}