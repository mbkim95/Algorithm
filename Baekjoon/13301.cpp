#include <iostream>
using namespace std;

long long w[81], ans[81];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	w[1] = w[2] = 1;
	ans[1] = 4;
	ans[2] = 6;
	for (int i = 3; i <= n; i++) {
		w[i] = w[i - 1] + w[i - 2];
		ans[i] = ans[i - 1] + 2 * w[i];
	}
	cout << ans[n] << '\n';
	return 0;
}