#include <iostream>
using namespace std;

const float PI = 3.141592;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int d1, d2;
	cin >> d1;
	cin >> d2;

	cout << fixed;
	cout.precision(6);
	cout << 2 * PI * d2 + 2 * d1 << '\n';
	return 0;
}