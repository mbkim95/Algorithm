#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum = 0, ans = 100;
		for (int i = 0; i < 7; i++) {
			int tmp;
			cin >> tmp;
			if (tmp % 2 == 0) {
				ans = min(ans, tmp);
				sum += tmp;
			}
		}
		cout << sum << ' ' << ans << '\n';
	}
	return 0;
}