#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k, d1, d2;
	cin >> k;
	cin >> d1 >> d2;
	if (d1 == d2) cout << k * k << '\n';
	else {
		float tmp = (float)(d1 - d2) / 2;
		cout<< fixed;
		cout.precision(6);
		cout << k * k - tmp * tmp << '\n';
	}
}