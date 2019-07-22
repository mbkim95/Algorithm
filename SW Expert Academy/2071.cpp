#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int sum = 0, ans;
		for (int i = 0; i < 10; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
		}
		if (sum % 10 < 5)
			ans = sum / 10;
		else
			ans = sum / 10 + 1;
		cout << "#" << c << ' ' << ans << '\n';
	}
	return 0;
}