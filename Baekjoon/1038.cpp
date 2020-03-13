#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<long long> nums;

	for (int i = 1; i <= 1023; i++) {
		long long num = 0;
		int tmp = i;
		for (int j = 9; j >= 0; j--) {
			if (tmp % 2 == 1)
				num = 10 * num + j;
			tmp /= 2;
		}
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int n;
	cin >> n;
	if (n > 1022)
		cout << "-1" << '\n';
	else
		cout << nums[n] << '\n';
	return 0;
}