#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	int ans = 0;
	for (int i = 1; i <= 1000000; i++) {
		int tmp = i, sum = i;
		vector<int> v;
		while (tmp) {
			v.push_back(tmp % 10);
			tmp = tmp / 10;
		}
		for (auto x : v) {
			sum += x;
		}
		if (sum == num) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}