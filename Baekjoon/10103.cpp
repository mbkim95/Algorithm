#include <iostream>
using namespace std;

int main() {
	int n, c, s, c_s = 100, s_s = 100;
	cin >> n;
	while (n--) {
		cin >> c >> s;
		if (c > s) s_s -= c;
		if (c < s) c_s -= s;
	}
	cout << c_s << '\n' << s_s << '\n';
	return 0;
}