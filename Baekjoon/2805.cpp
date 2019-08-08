#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> tree;

bool findHeight(int h) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (h < tree[i])
			sum += tree[i] - h;
	}
	return sum >= m;
}

int solve() {
	int left = 0;
	int right = tree[n - 1];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (findHeight(mid)) {
			if(ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	tree = vector<int>(n);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	cout << solve() << '\n';
	return 0;
}