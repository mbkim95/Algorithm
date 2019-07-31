#include <iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int round = 0;
	while (a != b) {
		round++;
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
	}
	cout << round << '\n';
	return 0;
}