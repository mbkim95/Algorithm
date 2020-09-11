#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int l[100001];

int binary_search(int r) {
	int ans = 987654321;
	int left = *max_element(l, l + n);
	int right = r;

	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += l[i];
			if (sum > mid) {
				cnt++;
				sum = l[i];
			}
		}
		if (sum <= mid) cnt++;

		if (cnt <= m) {
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
		cin >> l[i];
		sum += l[i];
	}

	cout << binary_search(sum) << '\n';
	return 0;
}