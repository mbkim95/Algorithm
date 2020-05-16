#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	if (t % 10 != 0) cout << -1 << '\n';
	else {
		int a = 0, b = 0, c = 0;
		while (t - 300 >= 0) {
			a++;
			t -= 300;
		}
		while (t - 60 >= 0) {
			b++;
			t -= 60;
		}
		while (t - 10 >= 0) {
			c++;
			t -= 10;
		}
		cout << a << ' ' << b << ' ' << c << '\n';
	}
	return 0;
}