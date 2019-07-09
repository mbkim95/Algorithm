#include <iostream>
#include <algorithm>
using namespace std;

int n, num[81];

bool check(int idx) {
	for (int i = 1; i <= idx / 2; i++) {
		if (equal(num + idx - i, num + idx, num + idx - i - i))
			return false;
	}
	return true;
}

void solve(int idx) {
	if (!check(idx))
		return;

	if (idx == n) {
		for (int i = 0; i < idx; i++) {
			cout << num[i];
		}
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		num[idx + 1] = i;
		solve(idx + 1);
		num[idx + 1] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	num[0] = 1;
	for (int i = 1; i <= 3; i++) {
		num[1] = i;
		solve(1);
		num[1] = 0;
	}
	return 0;
}