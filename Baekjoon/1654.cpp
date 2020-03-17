#include <iostream>
#include <vector> 
#include <limits>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector<int> len(k);
	for (int i = 0; i < k; i++)
		cin >> len[i];

	long long left = 0;
	long long right = numeric_limits<long long>::max();
	long long ans = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		int result = 0;

		for (int i = 0; i < len.size(); i++) {
			result += len[i] / mid;
		}

		if (result >= n) {
			left = mid + 1;
			if (mid > ans)
				ans = mid;
		}
		else
			right = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}