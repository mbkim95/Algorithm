#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cin >> n;
	int count = 0;
	long long ans = 0;
	while (n > 0) {
		if (n & 0x1) {
			long long mul = 1;
			for (int i = 0; i < count; i++)
				mul *= 3;
			ans += mul;
		}
		count++;
		n = n >> 1;
	}
	cout << ans << '\n';
	return 0;
}