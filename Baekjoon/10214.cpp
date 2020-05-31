#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int y = 0, k = 0;
		for (int i = 0; i < 9; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			y += t1; k += t2;
		}
		if (y > k) cout << "Yonsei\n";
		else if (y < k) cout << "Korea\n";
		else cout << "Draw\n";
	}
	return 0;
}