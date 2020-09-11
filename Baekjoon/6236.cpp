#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int money[100001];

bool is_possible(int mid) {
	int cnt = 1;
	int sum = mid;

	for (int i = 0; i < n; i++) {
		if (mid < money[i]) return false;

		if (sum - money[i] < 0) {
			sum = mid;
			cnt++;
		}
		sum -= money[i];
	}
	return cnt <= m;
}

int binary_search(int r) {
	int left = 1;
	int right = r;
	int ans = 987654321;

	while (left <= right) {
		int mid = (left + right) / 2;		
			
		if (is_possible(mid)) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		sum += money[i];
	}

	cout << binary_search(sum) << '\n';
	return 0;
}