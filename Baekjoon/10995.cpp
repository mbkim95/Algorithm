#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= 2 * n -1; j++) {
				if (j % 2 == 1)
					cout << '*';
				else
					cout << ' ';
			}
			cout << '\n';
		}else{
			for (int j = 1; j <= 2 * n; j++) {
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