#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans = 987654321;
int ball[301];

void binary_search(int r) {
	int left = *max_element(ball, ball + n);
	int right = r;

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += ball[i];
			if (sum > mid) {
				sum = ball[i];
				cnt++;
			}
		}
		if (sum <= mid) {
			cnt++;
		}

		if (cnt <= m) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += ball[i];
		if (sum > ans) {
			sum = ball[i];
			m--;
			cout << cnt << ' ';
			cnt = 0;
		}
		cnt++;
		if (n - i == m) break;
	}

	while (m--) {
		cout << cnt << ' ';
		cnt = 1;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> ball[i];
		sum += ball[i];
	}

	binary_search(sum);
	return 0;
}