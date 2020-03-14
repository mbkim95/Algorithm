#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
		if (n != 1) {
			for (int j = 1; j <= n; j++) {
				if (j % 2 == 0)
					cout << '*';
				else
					cout << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}