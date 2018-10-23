#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = a * b * c;
	int n[10] = { 0 };
	while (result) {
		n[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << n[i] << '\n';
	}
	return 0;
}