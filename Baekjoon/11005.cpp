#include <iostream>
using namespace std;

int n, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> b;
	string ans = "";

	while (n > 0) {
		if (n % b < 10) ans = (char)('0' + (n % b)) + ans;
		else ans = (char)('A' + (n % b - 10)) + ans;
		n /= b;
	}
	cout << ans << '\n';
	return 0;
}