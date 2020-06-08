#include <iostream>
using namespace std;

int n, f;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> f;
	n /= 100;
	int tmp, i;
	for (i = 0; i <= 99; i++) {
		tmp = n;
		tmp *= 100;
		tmp += i;
		if (tmp % f == 0) break;
	}
	if (i < 10) cout << 0 << i << '\n';
	else cout << i << '\n';
	return 0;
}