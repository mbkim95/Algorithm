#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	int max_value = 0;
	vector<int> money(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		max_value = max(money[i], max_value);
	}
	cin >> m;

	int ans;
	int left = 0;
	int right = max_value;

	while (left <= right) {
		int mid = (left + right) / 2;
		int total = 0;
		for (int i = 0; i < n; i++) 
			total += min(mid, money[i]);

		if (total <= m) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}