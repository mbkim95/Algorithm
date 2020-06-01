#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ans = 0;
	int p = 0;

	for (int i = 0; i < 10; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		p += (t2 - t1);
		ans = max(ans, p);
	}
	cout << ans << '\n';
	return 0;
}