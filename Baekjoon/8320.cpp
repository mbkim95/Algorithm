#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int square = floor(sqrt(n));
	int ans = 0;

	for (int i = 1; i <= square; i++) {
		for (int j = i; j <= n / i; j++) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}