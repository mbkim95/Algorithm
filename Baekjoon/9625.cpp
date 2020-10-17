#include <iostream>
using namespace std;

int main() {
	int k;
	cin >> k;
	int a = 1;
	int b = 0;
	for (int i = 0; i < k; i++) {
		int tmp_a = a;
		a = b;
		b += tmp_a;
	}
	cout << a << ' ' << b << '\n';
	return 0;
}