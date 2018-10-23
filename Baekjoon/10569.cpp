#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		int s = 3;

		while (v - e + s != 2) {
			s++;
		}
		cout << s << '\n';
	}

	return 0;
}