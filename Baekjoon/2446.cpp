#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= i - 1; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * (n + 1 - i) - 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = 1; i <= 2 * n - 1; i++) {
		if (i < n)
			cout << ' ';
		else if (i == n)
			cout << '*';
	}
	cout << '\n';
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i - 1; j++)
			cout << ' ';
		for (int j = 1; j <= 2 * (n + 1 - i) - 1; j++)
			cout << '*';
		cout << '\n';
	}
	return 0;
}