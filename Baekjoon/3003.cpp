#include <iostream>
using namespace std;

const int chess[] = { 1, 1, 2, 2, 2, 8 };

int main() {
	for (int i = 0; i < 6; i++) {
		int tmp;
		cin >> tmp;
		cout << chess[i] - tmp << ' ';
	}
	cout << '\n';
	return 0;
}