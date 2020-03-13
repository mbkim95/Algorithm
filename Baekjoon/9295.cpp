#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << "Case " << c << ": " << n1 + n2 << '\n';
	}
	return 0;
}