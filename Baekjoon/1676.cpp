#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int two = 0;
	int five = 0;
	int ans = 0;
	for (int i = n; i >= 2; i--) {
		int num = i;
		while (num % 2 == 0) {
			num /= 2;
			two++;
		}
		num = i;
		while (num % 5 == 0) {
			num /= 5;
			five++;
		}
	}
	ans = min(two, five);
	cout << ans << '\n';
	return 0;
}