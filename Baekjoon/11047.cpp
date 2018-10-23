#include <iostream>
using namespace std;

int main() {
	int coin[10];
	int n, k, ans = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	int i = n - 1;

	while (k != 0) {
		if (k / coin[i] > 0) {
			ans += (k / coin[i]);
			k -= (coin[i] * (k / coin[i]));
		}
		i--;
	}
	cout << ans << endl;
}