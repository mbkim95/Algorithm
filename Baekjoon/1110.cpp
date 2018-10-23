#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int tmp, cnt = 0;
	tmp = n;
	do {
		int a = tmp / 10;
		int b = tmp % 10;
		tmp = b * 10 + (a + b) % 10;
		cnt++;
	} while (n != tmp);
	cout << cnt << '\n';
	return 0;
}