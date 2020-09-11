#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int n, m;
int t[100001];

long long binary_search() {
	long long ans = numeric_limits<long long>::max();
	long long left = 1;
	long long right = (long long)(*max_element(t, t + n)) * (long long)m;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += mid / t[i];

		if (cnt < m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			ans = min(ans, mid);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> t[i];
	cout << binary_search() << '\n';
	return 0;
}