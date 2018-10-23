#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int l, p, v, i = 0;
	while (1) {
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0) {
			break;
		}
		cout << "Case " << ++i <<": " << (v/p)*l + min(l, v%p) << endl;
	}
}