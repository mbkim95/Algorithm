#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int cur = 0;
	for (int i = 0; i < 4; i++) {
		int out, in;
		cin >> out >> in;
		cur += (in - out);
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}