#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		tmp = tmp >= 40 ? tmp : 40;
		sum += tmp;
	}
	cout << sum / 5 << '\n';
	return 0;
}