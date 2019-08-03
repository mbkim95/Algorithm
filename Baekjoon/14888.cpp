#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, maxv, minv;
vector<int> num, op;

int getResult(int a, int b, int operation) {
	int ret;
	if (operation == 0) {
		ret = a + b;
	}
	else if (operation == 1) {
		ret = a - b;
	}
	else if (operation == 2) {
		ret = a * b;
	}
	else {
		ret = a / b;
	}
	return ret;
}

void dfs(int result, int operation, int num_idx) {
	result = getResult(result, num[num_idx], operation);
	if (num_idx == n - 1) {
		maxv = max(maxv, result);
		minv = min(minv, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i]--;
			dfs(result, i, num_idx + 1);
			op[i]++;
		}
	}
}

void solve() {
	for (int i = 0; i < 4; i++) {
		if (op[i] != 0) {
			op[i]--;
			dfs(num[0], i, 1);
			op[i]++;
		}
	}
}

int main() {
	cin >> n;
	num = vector<int>(n);
	op = vector<int>(n - 1);
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	maxv = -1000000001;
	minv = 1000000001;
	solve();
	cout << maxv << '\n' << minv << '\n';
	return 0;
}