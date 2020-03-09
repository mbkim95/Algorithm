#include <iostream>
using namespace std;

int main() {
	int t, r, e, c;
	cin >> t;
	while (t--) {
		cin >> r >> e >> c;
		int diff = r - (e - c);
		if (diff < 0)
			cout << "advertise" << '\n';
		else if (diff == 0)
			cout << "does not matter" << '\n';
		else
			cout << "do not advertise" << '\n';
	}
	return 0;
}