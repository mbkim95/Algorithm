#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int c, v;
		cin >> c >> v;
		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
	}
	return 0;
}