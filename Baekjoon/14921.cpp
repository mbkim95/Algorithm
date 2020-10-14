#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	int ans = 1e9 + 1;
	int s = 0, e = n - 1;

	while (true) {
		if (s == e) break;
		int sum = nums[s] + nums[e];
		if (abs(sum) < abs(ans)) ans = sum;
		if (sum > 0) e--;
		else if (sum < 0) s++;
		else break;	
	}
	cout << ans << '\n';
	return 0;
}