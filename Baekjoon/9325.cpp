#include <iostream>
using namespace std;

int main() {
	int t, s, n, q, p, sum;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> q >> p;
			sum += (q * p);
		}
		cout << sum + s << '\n';
	}
	return 0;
}