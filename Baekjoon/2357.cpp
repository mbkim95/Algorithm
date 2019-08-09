#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num, min_tree, max_tree;

int init(vector<int>& tree, int mode, int node, int start, int end) {
	if (start == end) 
		return tree[node] = num[start];
	else {
		int mid = (start + end) / 2;
		if(mode == 0)
			return tree[node] = min(init(tree, mode, 2 * node, start, mid), init(tree, mode, 2 * node + 1, mid + 1, end));
		else
			return tree[node] = max(init(tree, mode, 2 * node, start, mid), init(tree, mode, 2 * node + 1, mid + 1, end));
	}
}

int solve(vector<int>& tree, int mode, int node, int start, int end, int left, int right) {
	if (left > end || start > right) {
		if (mode == 0)
			return 1000000001;
		else
			return 0;
	}
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	if (mode == 0)
		return min(solve(tree, mode, 2 * node, start, mid, left, right), solve(tree, mode, 2 * node + 1, mid + 1, end, left, right));
	else
		return max(solve(tree, mode, 2 * node, start, mid, left, right), solve(tree, mode, 2 * node + 1, mid + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	num = vector<int>(n);
	int h = (int)ceil(log2(n));
	int size = 1 << (h + 1);
	min_tree = vector<int>(size);
	max_tree = vector<int>(size);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	init(min_tree, 0, 1, 0, n - 1);
	init(max_tree, 1, 1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << solve(min_tree, 0, 1, 0, n - 1, a - 1, b - 1) << ' ' << solve(max_tree, 1, 1, 0, n - 1, a - 1, b - 1) << '\n';
	}
	return 0;
}