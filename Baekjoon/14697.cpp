#include <iostream>
using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	bool find = false;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				if (a * i + b * j + c * k > n) break;
				if (a * i + b * j + c * k == n) {
					find = true;
					break;
				}
			}
			if (find) break;
		}
		if (find) break;
	}
	if (find) cout << "1\n";
	else cout << "0\n";
	return 0;
}