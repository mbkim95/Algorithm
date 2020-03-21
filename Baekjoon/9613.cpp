#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> num(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];
		long long ans = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(num[i], num[j]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}