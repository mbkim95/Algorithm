#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = n - i; j > 0; j--)
			cout << ' ';
		for (int j = 1; j <= i; j++)
			cout << '*';
		cout << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n; i++)
		cout << '*';
	cout << '\n';
	for (int i = n - 1; i >= 1; i--) {
		for (int j = n - i; j > 0; j--)
			cout << ' ';
		for (int j = 1; j <= i; j++)
			cout << '*';
		cout << ' ';
		cout << '\n';
	}
	return 0;
}