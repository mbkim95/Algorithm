#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num, tree;

int init(int node, int start, int end) {
	if (start == end) 
		return tree[node] = num[start];
	else {
		int mid = (start + end) / 2;
		return tree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
	}
}

int solve(int node, int start, int end, int left, int right) {
	if (left > end || start > right)
		return 1000000001;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(solve(2 * node, start, mid, left, right), solve(2 * node + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	num = vector<int>(n);
	int h = (int)ceil(log2(n));
	int size = 1 << (h + 1);
	tree = vector<int>(size);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << solve(1, 0, n - 1, a - 1, b - 1) << '\n';
	}
	return 0;
}