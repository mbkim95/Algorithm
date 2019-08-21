#include <iostream>
using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	if (n == 1 || m == 1)
		cout << 1 << '\n';
	else if (n == 2) {
		if (m < 3)
			cout << 1 << '\n';
		else if (m < 5)
			cout << 2 << '\n';
		else if (m < 7)
			cout << 3 << '\n';
		else
			cout << 4 << '\n';
	}
	else if (n >= 3) {
		if (m == 2)
			cout << 2 << '\n';
		else if (m < 5)
			cout << m << '\n';
		else if (m < 7)
			cout << 4 << '\n';
		else if (m >= 7)
			cout << m - 2 << '\n';
	}
	return 0;
}