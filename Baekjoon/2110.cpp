#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> home(n);

	for (int i = 0; i < n; i++) 
		cin >> home[i];
	
	sort(home.begin(), home.end());

	int left = 1;
	int right = home[n - 1] - home[0];
	int ans;

	while (left <= right) {
		int mid = (left + right) / 2;
		int start = home[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (mid <= home[i] - start) {
				cnt++;
				start = home[i];
			}
		}

		if (cnt < c)
			right = mid - 1;
		else {
			ans = mid;
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}