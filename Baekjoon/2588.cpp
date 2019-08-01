#include <iostream>
using namespace std;

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	int tmp = n2;
	for (int i = 0; i < 3; i ++) {
		cout << n1 * (tmp % 10) << '\n';
		tmp /= 10;
	}
	cout << n1 * n2 << '\n';
	return 0;
}